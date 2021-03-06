#include "image.hh"


class ImageNB : public Image
{
    public:
        ImageNB(std::string picture_name);
        virtual ~ImageNB() override;
        
        /* create the matrix of (uint8_t ** matrix ) that will contain the pixels */
        virtual void create_matrice() override;

        /* create the buffer that will contain the information between the 
         header part and the beginning of the picture */
        void create_buffer();

        /* load the image information in the header object and the pixel part in the buffer */
        virtual void load_image() override;

        /*restore all the information in a new image file with a new name */
        virtual void reload_image(std::string output_fname) override;

        /*load the buffer in the image file*/
        void reload_buffer(); 

        /*print the header of the image */
         virtual void copy_pix_matrice() override;

         uint8_t **pic_pix_get() const;

         /*return true if the function has an 8 bit format */
        bool is_8bit_pic() const;

        /*state get*/

        bool is_good() const;

        /*convertion type to bool */

        operator bool () const;

    protected :
        
        uint8_t *buffer_ = nullptr;
        uint8_t **pic_pix_ = nullptr;
};
