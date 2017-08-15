#pragma once
#include <vector>
#include <memory>
#include "header.hh"

class Image
{

    public:

        virtual ~Image();

        /* create the matrix of (uint8_t ** matrix ) that will contain the pixels */
        virtual void create_matrice() = 0;

        /* create the buffer that will contain the information between the 
         header part and the beginning of the picture */
        virtual void create_buffer() = 0;

        /* load the image information in the header object and the pixel part in the buffer */
        virtual void load_image() = 0;

        /*restore all the information in a new image file with a new name */
        virtual void reload_image(std::string output_fname) = 0;

        /**/
        virtual void copy_pix_matrice() = 0;


        /*load the buffer in the image file*/
        virtual void reload_buffer() = 0; 

        /*print the header of the image */

        void print_header() const; 
   
   protected:
 
        Header header_;
        uint8_t *buffer_; 
        uint8_t **pic_pix_;
        std::string name_;
        
        std::ifstream istream_;
        std::ofstream  ostream_;
};
