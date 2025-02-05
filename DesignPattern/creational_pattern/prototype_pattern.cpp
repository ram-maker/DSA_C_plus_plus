/*Prototype pattern is used because:
1.Creating an object is expensive then copying it
2.Almost most the object creation is same
3.Some may argue that if overall idea is to copy the existing copy constructor then why not use copy constructor.Well the copy constructor needs
is tightly coupled with its object while prototype pattern isnt
*/
#include <iostream>
#include <memory>
using namespace std;

class Media {
public:
    virtual shared_ptr<Media> clone() = 0;
    virtual void display() = 0;

    virtual void setSource(const string& source) = 0;
    virtual void setSize(int size) = 0;
    virtual void setExtension(const string& extension) = 0;

    virtual ~Media() = default;
};

class ImageMedia : public Media {
    string source;
    int image_size;
    string extension;

public:
    ImageMedia() : source(""), image_size(0), extension("") {}

    void setSource(const string& source) override {
        this->source = source;
    }

    void setSize(int image_size) override {
        this->image_size = image_size;
    }

    void setExtension(const string& extension) override {
        this->extension = extension;
    }

    shared_ptr<Media> clone() override {
        return make_shared<ImageMedia>(*this); // Correctly clone the derived class
    }

    void display() override {
        cout << "Image Source: " << source << "\n"
             << "Image Size: " << image_size << "\n"
             << "Extension: " << extension << endl;
    }
};

int main() {
    shared_ptr<Media> png_media = make_shared<ImageMedia>();
    png_media->setSource("Img/");
    png_media->setSize(1024);
    png_media->setExtension(".png");
    png_media->display();

    shared_ptr<Media> jpeg_media = png_media->clone();
    jpeg_media->setExtension("jpeg");
    cout << "\nCloned and Mutated Media:\n";
    jpeg_media->display();

    return 0;
}

