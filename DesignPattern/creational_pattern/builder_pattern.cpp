#include <iostream>
using namespace std;
class Url{
    private:
    string host_name="";
    string protocol_name="";
    string port_name="";
    string param_name="";
    string query_param="";
    public:
        void setHost(const string &host_name){
            this->host_name=host_name;
        }
        void setProtocol(const string &protocol_name){
            this->protocol_name=protocol_name;
        }
        void setPort(const string &port_name){
            this->port_name=port_name;
        }
        void setParamPath(const string &param_name){
            this->param_name=param_name;
        }
        void setQueryParam(const string &query_param){
            this->query_param=query_param;
        }
        void display(){
            cout<<"Url: ";
            cout<<this->protocol_name<<"://"<<this->host_name<<"/"<<this->param_name<<"?"<<this->query_param<<endl;
        }

};
class UrlBuilder{
    private:
        Url url;
    public:
        UrlBuilder& setHost(const string &host_name){
            url.setHost(host_name);
            return *this;
        }

        UrlBuilder& setProtocol(const string &protocol_name){
            url.setProtocol(protocol_name);
            return *this;
        }

        UrlBuilder& setPort(const string &port){
            url.setPort(port);
            return *this;
        }

        UrlBuilder& setParamPath(const string &param_path){
            url.setParamPath(param_path);
            return *this;
        }

        UrlBuilder& setQueryParam(const string &query_param){
            url.setParamPath(query_param);
            return *this;
        }

        Url build(){
            return url;
        }
    
};
class UrlDirector{
    public:
        Url build(UrlBuilder url_builder){
            return url_builder.setProtocol("http")
            .setHost("localhost:8000")
            .setPort("80")
            .build();
        }
    
};
int main(){
    UrlBuilder url_builder;
    UrlDirector urldirecor;
    Url url=urldirecor.build(url_builder);
    url.display();
    return 0;
}