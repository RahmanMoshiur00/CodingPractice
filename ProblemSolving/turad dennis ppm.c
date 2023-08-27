#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>
#include <string.h>


typedef struct Color
{
    int R;
    int G;
    int B;
} Color;


typedef struct Image
{
    Color *image;
    int rows; //height
    int cols; //width
} Image;


Image* read_PPM(char *filename)
{

    /* opens a PPM file, constructs an Image object and returns a pointer to it.
    Use fopen(), fscanf(), fprintf(), and fclose().*/

    Image *img, *im;
    FILE *fp;
    int c, rgb_comp_color;
    char str[16];

    //open PPM file for reading
    fp = fopen(filename, "r");

    //read image format //1st line
    fgets(str, sizeof(str), fp);

    //allocate memory form image
    img = (Image *)malloc(sizeof(Image));

    //read image size information //2nd line
    fscanf(fp, "%d %d", &img->cols, &img->rows);

    //read rgb component //3rd line
    fscanf(fp, "%d", &rgb_comp_color);

    while (fgetc(fp) != '\n');

    //memory allocation for pixel data
    img->image = (Color*)malloc(img->cols * img->rows * sizeof(Color));

    int count = 0, r, g, b, x, i = 0;
    while(fscanf(fp, "%d", &x) != EOF){
        count %= 3;
        if(count==0) r = x;
        else if(count == 1) g = x;
        else b = x;
        if(count == 2){
            img->image[i].R = r;
            img->image[i].G = g;
            img->image[i].B = b;
            i++;
        }
        count++;
    }

    fclose(fp);
    return img;
}

void get_secret_image(Image *img)
{
    int i;
    for(i=0;i<img->cols*img->rows;i++){
        if(img->image[i].B % 2 == 0){ //black color
            img->image[i].R = 0;
            img->image[i].G = 0;
            img->image[i].B = 0;
        }
        else{
            img->image[i].R = 255;
            img->image[i].G = 255;
            img->image[i].B = 255;
        }
    }
}

void write_PPM(Image *img, char *filename)
{
    /* takes an Image object and writes to filename in PPM format.*/

    FILE *fp;
    //open file for output
    fp = fopen(filename, "wb");

    //image format //1st line
    fprintf(fp, "P3\n");

    //image size //2nd line
    fprintf(fp, "%d %d\n", img->cols, img->rows);

    // rgb component depth
    fprintf(fp, "255\n");

    // pixel data
    int i, count = 0;
    for(i=0; i < img->cols * img->rows; i++){
        count %= img->cols;
        if(count) fprintf(fp, " ");
        fprintf(fp, "%d %d %d", img->image[i].R, img->image[i].G, img->image[i].B);
        if(count == img->cols - 1) fprintf(fp, "\n");
        count++;
    }
    fclose(fp);
}

void free_image(Image *img)
{
    /* takes an Image object and frees all the memory associated with it.
    This involves not only calling free on image but also on the appropriate
    members of it.
    */

    free(img->image);
    free(img);
}

int main()
{
    /* Call read_PPM(), write_PPM(), free_image(), get_secret_image() in some order
    to obtain the hidden message.*/

    Image *image;
    image = read_PPM("DennisRitchie.ppm");
    get_secret_image(image);
    write_PPM(image, "DennisRitchie_my_new.ppm");
    free_image(image);

    return 0;
}
