# include <complex.h>
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <time.h>

# include <omp.h>

int main ( );
void mandelbrot_image ( float xmin, float xmax, float ymin, float ymax, 
  int xnum, int ynum, int count_max );
int *mandelbrot_set ( float xmin, float xmax, float ymin, float ymax, int xnum, 
  int ynum, int count_max );
int mandelbrot_count ( _Complex float c, int count_max );
void pgma_write ( char *file_name, char *comment, int xsize, int ysize, 
  int maxval, int *gray );

/******************************************************************************/

int main ( )

/******************************************************************************/
/*
  Purpose:

    MANDELBROT_OPENMP creates an image of the Mandelbrot set.

  Discussion:

    Over the rectangle [XMIN,XMAX] x [YMIN,YMAX], determine the Mandelbrot
    count for a grid of XNUMxYNUM points, using a particular value of
    COUNT_MAX.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    15 May 2017

  Author:

    John Burkardt

  Local Parameters:

    Local, float XMIN, XMAX, YMIN, YMAX, the physical limits of the rectangle.

    Local, int XNUM, YNUM, the number of points in X and Y directions.

    Local, int COUNT_MAX, the maximum number of iterations.
*/
{
  int count_max;
  float xmax;
  float xmin;
  int xnum;
  float ymax;
  float ymin;
  int ynum;

  printf ( "\n" );
  printf ( "MANDELBROT_OPENMP:\n" );
  printf ( "  C/OPENMP version\n" );
  printf ( "  Compute the Mandelbrot set and display it.\n" );

  xmin = -1.0;
  xmax = -0.6;
  ymin = 0.0;
  ymax =  0.4;
  xnum = 1000;
  ynum = 1000;
  count_max = 200;

  printf ( "\n" );
  printf ( "  X range: [ %g, %g ]\n", xmin, xmax );
  printf ( "  Y range: [ %g, %g ]\n", ymin, ymax );
  printf ( "  Xnum = %d x Ynum = %d = %d Pixels\n", xnum, ynum, xnum * ynum );
  printf ( "  Maximum number of iterations = %d\n", count_max );

  mandelbrot_image ( xmin, xmax, ymin, ymax, xnum, ynum, count_max );
/*
  Terminate.
*/
  printf ( "\n" );
  printf ( "MANDELBROT_OPENMP:\n" );
  printf ( "  Normal end of execution.\n" );
  return 0;
}
/******************************************************************************/

void mandelbrot_image ( float xmin, float xmax, float ymin, float ymax, 
  int xnum, int ynum, int count_max )

/******************************************************************************/
/*
  Purpose:

    MANDELBROT_IMAGE creates an image of the Mandelbrot set.

  Discussion:

    Over the rectangle [XMIN,XMAX] x [YMIN,YMAX], determine the Mandelbrot
    count for a grid of XNUMxYNUM points, using a particular value of
    COUNT_MAX.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    15 May 2017

  Author:

    John Burkardt

  Parameters:

    Input, float XMIN, XMAX, YMIN, YMAX, the physical limits of the rectangle.

    Input, int XNUM, YNUM, the number of points in X and Y directions.

    Input, int COUNT_MAX, the maximum number of iterations.
*/
{
  char comment[] = "PGM gray map created by mandelbrot_openmp.c";
  int *count;
  char *file_name = "mandelbrot_openmp.ppm";
  double t1;
  double t2;
  double value;

  t1 = omp_get_wtime ( );
  count = mandelbrot_set ( xmin, xmax, ymin, ymax, xnum, ynum, count_max );
  t2 = omp_get_wtime ( );

  printf ( "\n" );
  printf ( "  Compute time:\n" );

  value = t2 - t1;
  printf ( "  Wallclock: %.02f sec.\n", value );
/*
  Write data to PGM file.
*/
  pgma_write ( file_name, comment, xnum, ynum, count_max, count );

  printf ( "\n" );
  printf ( "  Plot saved in file '%s'\n", file_name );
/*
  Free memory.
*/
  free ( count );

  return;
}
/******************************************************************************/

int *mandelbrot_set ( float xmin, float xmax, float ymin, float ymax, int xnum, 
  int ynum, int count_max )

/******************************************************************************/
/*
  Purpose:

    MANDELBROT_SET computes the Mandelbrot count for a grid of points.

  Discussion:

    Over the rectangle [XMIN,XMAX] x [YMIN,YMAX], determine the Mandelbrot
    count for a grid of XNUMxYNUM points, using a particular value of
    COUNT_MAX.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    15 May 2017

  Author:

    John Burkardt

  Parameters:

    Input, float XMIN, XMAX, YMIN, YMAX, the physical limits of the rectangle.

    Input, int XNUM, YNUM, the number of points in X and Y directions.

    Input, int COUNT_MAX, the maximum number of iterations.

    Output, int MANDELBROT_SET[XNUM*YNUM], the count for each point in the grid.
*/
{
  float complex c;
  int *count;
  int i;
  int j;
  float x;
  float y;

  count = ( int * ) malloc ( xnum * ynum * sizeof ( int ) );

# pragma omp parallel private ( c, i, j, x, y )
{
# pragma omp for

  for ( i = 0; i < xnum; i++ )
  {
    x = ( ( float ) ( xnum - 1 - i ) * xmin 
        + ( float ) (            i ) * xmax ) 
        / ( float ) ( xnum - 1     );

    for ( j = 0; j < ynum; j++ )
    {
      y = ( ( float ) ( ynum - 1 - j ) * ymax
          + ( float ) (            j ) * ymin ) 
          / ( float ) ( ynum - 1     );

      c = x + y * I;

      count[i+j*xnum] = mandelbrot_count ( c, count_max );
    }
  }
}
  return count;
}
/******************************************************************************/

int mandelbrot_count ( float complex c, int count_max )

/******************************************************************************/
/*
  Purpose:

    MANDELBROT_COUNT returns the Mandelbrot count for a single point.

  Discussion:

    Starting with the value 0, repeatedly square and add complex value C.

    Return number of applications of this process at which the
    value exceeds 2 in norm.

    Repeat no more than COUNT_MAX times.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    15 May 2017

  Author:

    John Burkardt

  Parameters:

    Input, float complex C, the value added at each step.

    Input, int COUNT_MAX, the maximum number of iterations.

    Output, int MANDELBROT_COUNT, the number of operations at which
    the iterate first exceeded 2 in norm.  If this never happens,
    return COUNT_MAX.
*/
{
  int k;
  int value;
  float complex z;

  value = count_max;

  z = 0.0 + 0.0 * I;
  for ( k = 0; k < count_max; k++ )
  {
    if ( 2.0 <= cabs ( z ) )
    {
      value = k;
      break;
    }
    z = z * z + c;
  }

  return value;
}
/******************************************************************************/

void pgma_write ( char *file_name, char *comment, int xsize, int ysize, 
  int maxval, int *gray )

/******************************************************************************/
/*
  Purpose:

    PGMA_WRITE writes the header and data for an ASCII PGM file.
 
  Example:

    P2
    # feep.pgm
    24 7
    15
    0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0
    0  3  3  3  3  0  0  7  7  7  7  0  0 11 11 11 11  0  0 15 15 15 15  0
    0  3  0  0  0  0  0  7  0  0  0  0  0 11  0  0  0  0  0 15  0  0 15  0
    0  3  3  3  0  0  0  7  7  7  0  0  0 11 11 11  0  0  0 15 15 15 15  0
    0  3  0  0  0  0  0  7  0  0  0  0  0 11  0  0  0  0  0 15  0  0  0  0
    0  3  0  0  0  0  0  7  7  7  7  0  0 11 11 11 11  0  0 15  0  0  0  0
    0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:
 
    13 May 2017
 
  Author:
 
    John Burkardt

  Parameters:

    Input, char *FILE_NAME, the name of the file.

    Input, char *COMMENT, a comment.

    Input, int XSIZE, YSIZE, the number of rows and columns of data.

    Input, int MAXVAL, the maximum value allowed.

    Input, int *GRAY, the array of XSIZE by YSIZE data values.
*/
{
  FILE *file_handle;
  int i;
  int *indexg;
  int j;
/*
  Open the output file.
*/
  file_handle = fopen ( file_name, "wt" );

  if ( ! file_handle )
  {
    fprintf ( stderr, "\n" );
    fprintf ( stderr, "PGMA_WRITE - Fatal error!\n" );
    fprintf ( stderr, "  Cannot open the output file \"%s\".\n", file_name );
    exit ( 1 );
  }
/*
  Write the header.
*/
  fprintf ( file_handle, "P2\n" );
  fprintf ( file_handle, "#%s\n", comment );
  fprintf ( file_handle, "%d %d\n", xsize, ysize );
  fprintf ( file_handle, "%d\n", maxval );
/*
  Write the data.
*/
  indexg = gray;

  for ( j = 0; j < ysize; j++ )
  {
    for ( i = 0; i < xsize; i++ )
    {
      fprintf ( file_handle, " %d", *indexg );
      indexg = indexg + 1;
    }
    fprintf ( file_handle, "\n" );
  }
/*
  Close the file.
*/
  fclose ( file_handle );

  return;
}
