    
	//C语言中重复定义的问题
	//2014-07-26
	
	
	//几个基本知识：
    
    //1、头文件：头文件的作用在于编译时，会在#include <*.h>位置处展开，所以如果有多个.c文件include同一个头文件（很常见）。
    //如果头文件编写时不进行处理，出现重复定义是不可避免的。尤其是当一个项目分成多个模块的时候。
    
    //2、一般，把函数、变量、结构体、类等放在.c或者.cpp文件中，编译生成.o、.dll等给其他文件使用。
    
    //3、头文件一般放函数、变量、类的声明。
    
    //4、不允许被其他文件使用的函数用static定义，否则默认为extern。
    
    //5、一般不要在头文件中定义变量、函数、类，否则容易产生重复定义。
    
    //6、要使用其他模块（文件）定义的函数、变量等，直接包含其头文件。
    
        //例子：
		
		    //----------
        
            //a.c
        
            #include <stdio.h>
        
            void Print(void){
        
                printf("test\n");
        
            }
        
            //----------
        
            //a.h
        
            void Print(void);  //声明Print函数
        
            //----------
        	
            //b.c
        
            #include <a.h>
        
            main(){
        
                Print();
        
            }
        	
        	//----------
        
            //编译后运行，打印出"test"。
        
    //我们经常遇到这样一种情况，需要定义一个结构体，这个结构体可能要在多个文件中使用。
    
    //们把结构体定义在头文件中，其他文件要使用时，只需要include就可以了，不幸的是，编译的时候会出现重复定义的提示。
    
    //简单，多次include展开时，头文件中定义的结构体会被多次定义。
    
    //在f1.c中有#include <a.h>，f2.c中也有#include <a.h>，那么a.h就会展开两次，结构体就重复定义了，这时候就需要对头文件进行处理了。
    
    //例子：
    
    //1、在 struct.h中定义了一个结构体sqlist：
	
	    //----------
    
        //struct.h
        
        #ifndef STRU_H      //这个STRU_H是随意取的，但是最好是有意义并且不与其他重复：
        
        #define STRU_H
        
        typedef struct{
        
            int length;
        
            int listsize;
        
        }Sqlist;
        
        #endif
		
		//----------
    
    //2、在文件f1.c中定义了一个函数Initlist对结构体进行初始化操作：
	
	    //----------
    
        //f1.c
        
        #include<struct.h>
        
        #include<stdio.h>
        
        void Initlist(Sqlist *L){
        
            L->length=0;
        
            L->listsize=100;
        
        }
		
		//----------
    
    //3、在头文件f1.h中对函数进行声明：
	
	    //----------
    
        //f1.h
        
        #ifndef FUN1_H
        
        #define FUN1_H
        
        void Initlist(Sqlist *L);
        
        #endif
		
		//----------
    
    //4、在文件f2.c中有main函数定义了一个结构体类型变量，并调用外部函数Initlist进行初始化：
    
	    //----------
	    
        //f2.c
        
        #include<stdio.h>
        
        #include<struct.h> //为了使用结构体类型
        
        #include<f1.h> //为了调用外部函数
        
        void main(){
        
            Sqlist La;
        
            Initlist(&La);
        
            printf("%d,%d\n",La.length,La.listsize);
        
        }
	    
	    //----------
    
    //5、正确编译，运行，得到结果 0，100。
