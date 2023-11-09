#include <iostream>
#include <string>
#include <cmath>
#include<cassert>
#include <fstream>

using namespace std;


class functionCalculate{
    private:
    
        FILE *f;
        
        string inputData ="";
        
        int x;
        
        int y;
        
    public:
        functionCalculate(const string& fileName){
            
            openFile(fileName);
        
            parseFile();
            
            calc(inputData);
            
            writeToFile();
            
            
        }
        
        ~functionCalculate(){
            closeFile();
        }
        
        void writeToFile(){
            FILE *t;
            t=fopen("result_func.txt","w");
            fprintf(t,"%d %d",x,y);
            fclose(t);
        }
        void openFile(const string& fileName){
            const char * finFileName = fileName.c_str();
            f=fopen( finFileName,"r");
        }
        
        void closeFile() {
            fclose(f);
        }
        
        void  parseFile() {
        
            char val[12800];
       
            while(!feof(f)){
                fscanf(f,"%s",val);
            }
        
            inputData = val ;
        }
        
        int calc(string input){
    
            int suma = 0;
            int i = 0;
            
            
            while (i != sizeof input * 8){
                int sumai = 0;
                
                if(input[i] == '^'){
            	    x = input[i-1] - '0';	 
                    sumai = pow(input[i-1] - '0', input[i+1] - '0');
            
                    sumai = sumai * (input[i-3] - '0');
            
                }
            
                suma = sumai + suma;
                i = i + 1;
            }
            y = suma;
            return(suma);
        }

       string calcTest(){
    
            assert(calc("7*1^6+4*2^5+3*5^6") == 47010);
	    assert(calc("5*3^2+3*4^0") == 48);
            assert(calc("0*1^6+0*2^5+1*5^6") == 15625);
            assert(calc("7*1^1+4*2^1+3*5^1") == 30);
            assert(calc("3*5^4+6*7^3+1*2^2+0*1^1+7*4^1") == 3965);
    
            return ("calc is OK");
        }

};



int main()
{
   
    functionCalculate obj1{"func.txt"};
    cout<<obj1.calcTest()<<endl;
    return 0;
}
