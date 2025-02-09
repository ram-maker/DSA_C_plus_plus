/*
This is the simplest design pattern, simplest in the sense that, it creates a pathway for interacting vatrious object
In the following example, instead of doing all the operation required to encode a video, a facade class, does all the hardwork, and greatly makes client code
much cleaner
*/
/*subsystem 1, consider this as third party library*/
#include <iostream>
#include <memory>
using namespace std;
class Encoder{
    public:
    string findEncoder(string media){
        if (media=="audio"){
            return "aac";
        }else{
            return "H265";
        }
        
    }
    void findBitRate();
    void setSampleRate();
    Encoder encode();

};

/*subsystem 2, consider this as third party library*/
class Decoder{
    public:
    string findDecoder(string media){
        if (media=="audio"){
            return "aac d";
        }else{
            return "H265 d";
        }
    }

    void findBitRate();
    void setSampleRate();
    Decoder decode();

};

/*subsystem 3, consider this as third party library*/
class InputConetext{
    public:
    void findInputStreamInfo();
    void findInputCodec();
    void setInputContext();

};

/*subsystem 4, consider this as third party library*/
class OutputConetext{
    public:
    void setOutputStreamInfo();
    void setOutputCodec();
    string setOutputContext(string output_context){
        return "Output Context:"+output_context;
    }
};

/*subsystem 5, consider this as third party library*/
class EncoderContext{
    public:
    void setEncoderFrameSize();
    string setSamplerate(string sample_rate){
        return sample_rate;
    }
    EncoderContext getEncoderConetxt();
};

/*subsystem 6, consider this as third party library*/
class DecoderConext{
    public:
    void setDecoderFrameSize();
    void setDecoderSamplerate();
    DecoderConext getDecoderConext();

};

class VideoEncoderFacade{
    shared_ptr<Encoder> encoder;
    shared_ptr<OutputConetext> output_context;
    string encoder_codec;
    string output_context_container;
    public:
    VideoEncoderFacade(string input_file_path, string output_file_path){
        this->encoder_codec=encoder->findEncoder("video");
        this->output_context_container=output_context->setOutputContext(encoder_codec);
        
    }

    void encode(){
        cout<<"Encoding.."<<"\n"<<"Encoder codec:"<<encoder_codec<<"\n"<<"Output Context:"<<output_context_container<<endl;
    }

    
};
 int main(){
    VideoEncoderFacade video_encoder("typ.mp4","output.mp4");
    video_encoder.encode();
 }
