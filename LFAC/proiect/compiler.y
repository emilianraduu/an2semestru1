%{
#include <sstream>
#include <string>
#include <map>
#include <stdio.h>
#include <stdlib.h> 
#include <algorithm>
#include <iostream>
#include <vector>
#include <ctype.h>
#include <string.h>
#include <time.h>
#define MAX 1000

using namespace std;

	extern FILE *yyin;
    int yylex(void);
    void yyerror(char *);
	void identifer_type(string str);
	void insert_tokentable(string str1);
	void   update_tokentable(string str2);
	string get_variable_value(string myvar);
	

	
map < string, int > typeCheck;	
int tokenCount = 0;	
bool value_flag = false;


int temp_int=0;
float temp_float=0.0;
string temp_char="";


int var_pos=0;

int int_value=0;
float float_value = 0.0;
string char_value = "";
string char_temp_value = "";

string check = "";



string var_name = "";
string var_value = "";
string var_type = "";

	
	struct tokenTable{
                 string token_Name;
                 string token_Type;
                 string token_Value;
	}token_No[MAX];
	
	
	
	
%}


%union{
    float fval;
	int ival;
	char *cval;
	char *type;
}



%token <ival> INTVAL 
%token <cval> VAR 
%token <fval> FLOATVAL 
%token <cval> CHARVAL 
%token <cval> PRINTF
%token WHILE IF FOR ELSE
%token TYPEINT TYPELONG TYPEFLOAT TYPEDOUBLE TYPECHAR EQ SEM NL COM SQ RETURN MAIN VOID
%left '+' '-'
%left '*' '/'
%left ','



%%

stm :         stm code {}
             |
			 ;
           			 							 

		
		
code :	     TYPEINT varlist SEM   { identifer_type("int"); }
             |
             TYPELONG varlistlong SEM   { identifer_type("long"); }
			 |
             TYPEFLOAT varlistfloat SEM   { identifer_type("float"); }
			 |	
             TYPEDOUBLE varlistdouble SEM   { identifer_type("double"); }
			 |
             TYPECHAR varlistchar SEM   { identifer_type("char"); }
             |
             VAR { var_name=$<cval>1; if(typeCheck[var_name]==0)
							            {
							                printf("Undefined Variable!\n");
								            cout<<"Variable Name:" <<var_name<<endl;
											exit(0);
							             }
										} EQ expn SEM       
    									  { 
                                             if(typeCheck[var_name]==1)
											   {
											      int_value = temp_int;
												  update_tokentable("int");
											   }
											 else if(typeCheck[var_name]==2)
											   {
											      int_value = temp_int;
												  update_tokentable("long");
											   }
											 else if(typeCheck[var_name]==3)
											   {
											      float_value = temp_float;
												  update_tokentable("float");
											   }
											 else if(typeCheck[var_name]==4)
											   { 
											      float_value = temp_float;
												  update_tokentable("double");
											   }
											 else if(typeCheck[var_name]==5)
											   {
											      char_value = temp_char;
												  update_tokentable("char");
											   }
																					 
							        }
			|
			  myprintf             {}
			|
              RETURN               {identifer_type("return");}
            | 
              MAIN                 {identifer_type("main");}		  
            | 
              VOID                 {identifer_type("void");}	
			| 
				WHILE				{printf("while");}	
			|
				IF					{printf("if");}
			|
				FOR					{printf("for");}
			|
				ELSE				{printf("else");}	
			;

	
			 

			 
expn:    expn '+' expn {
                         
                          
						  if(typeCheck[var_name]==1 || typeCheck[var_name]==2)
						  {
                           $<ival>$=$<ival>1+$<ival>3;
						   temp_int = $<ival>$;
						   }
						  else if(typeCheck[var_name]==3 || typeCheck[var_name]==4)
						  {
						   $<fval>$=$<fval>1+$<fval>3;
						   temp_float = $<fval>$;
						   
						  }
					   }
      |	expn '-' expn {
	                      if(typeCheck[var_name]==1 || typeCheck[var_name]==2)
						  {
                           $<ival>$=$<ival>1-$<ival>3;
						   temp_int = $<ival>$;
						  }
						 else if(typeCheck[var_name]==3 || typeCheck[var_name]==4)
						  {
						   $<fval>$=$<fval>1-$<fval>3;
						   temp_float = $<fval>$;
						  }
					  }	
	  |	expn '*' expn {
	                     if(typeCheck[var_name]==1 || typeCheck[var_name]==2)
						 {
                          $<ival>$=$<ival>1*$<ival>3;
						  temp_int = $<ival>$;
						 }
						 else if(typeCheck[var_name]==3 || typeCheck[var_name]==4)
						 {
						  $<fval>$=$<fval>1*$<fval>3;
						  temp_float = $<fval>$;
						 }
	                  }	
	  |	expn '/' expn {
	  
	                   if(typeCheck[var_name]==1 || typeCheck[var_name]==2)
					   {
						   if($<ival>3 == 0)
					         {
						        printf("Can not divide by 0\n");
						        exit(0);
						   
						     }
							 else
							 {
							  $<ival>$=$<ival>1/$<ival>3;
							  temp_int = $<ival>$;
							 }
						}
						
						else if(typeCheck[var_name]==3 || typeCheck[var_name]==4)
						{
					     if($<fval>3 == 0)
					         {
						        printf("Can not divide by 0\n");
						        exit(0);
						     }
						  else
						  {
					        $<fval>$=$<fval>1/$<fval>3;
							temp_float = $<fval>$;
						  }
					    }
					   
					  }
  
					  
					
	  | '('expn')' {  
	                     if(typeCheck[var_name]==1 || typeCheck[var_name]==2)
						 {
	                         $<ival>$=$<ival>2;
							 temp_int = $<ival>$;
							 
						 }
						 
					else if(typeCheck[var_name]==3 || typeCheck[var_name]==4)
					    {
	                        $<fval>$=$<fval>2;
							temp_float = $<fval>$;
						}
						  
				  }
						  
      | INTVAL  {     
	                       if(typeCheck[var_name]==1 || typeCheck[var_name]==2)
						   {
	                         $<ival>$=$<ival>1;
							 temp_int = $<ival>$;
							}
					 	  else if(typeCheck[var_name]==3 || typeCheck[var_name]==4)
						   {
							 $<fval>$=$<ival>1;
							 temp_float = $<fval>$;
						   }
							 
						  
				  }
				  
	   | FLOATVAL {
                        	if(typeCheck[var_name]==1 || typeCheck[var_name]==2)
                              {
							  printf("Float to Int Convertion!\n");
							  exit(0);
                              }							  
	                        else if(typeCheck[var_name]==3 || typeCheck[var_name]==4)
							{
	                         $<fval>$=$<fval>1;
							 temp_float = $<fval>$;
							}
						  
				  }
        | CHARVAL {      if(typeCheck[var_name]==5)
		                     {
	                           $<cval>$=$<cval>1;
							   temp_char = $<cval>$[1];
							 }
						else
                           {
						    printf("Wrong Formation!\n");
							exit(0);
                           }						   
				  }
		
		| VAR   {   
            		string myvar = $<cval>1;
		          int my_intValue;
				  float my_floatValue;
				  string my_charValue;
	                    	
		             if(typeCheck[myvar]==0)
					   {
					     cout<<"In Variable Expression -- Undefined Variable!\n"<<"Variable Name: "<<myvar<<endl;
						 exit(0);  
					   }
					 else if(typeCheck[var_name]==1 || typeCheck[var_name]==2)
					   {
					            if(typeCheck[myvar]==1 || typeCheck[myvar]==2) 
					                {
					                  std::stringstream ss(get_variable_value(myvar));
									  ss >> my_intValue;
                                      $<ival>$ = my_intValue;	
                                      temp_int = $<ival>$;						
					                }
								else
                                   {
								      if(typeCheck[myvar]==3 || typeCheck[myvar]==4) 
					                    {
										 cout<<"Int Variable "<<var_name<<" is trying to assign Float Variable "<<myvar<<endl;
										 exit(0);
                                        }
									  else if(typeCheck[myvar]==5) 
					                    {
										 cout<<"Int Variable "<<var_name<<" is trying to assign Character Variable "<<myvar<<endl;
										 exit(0);
                                        }
									  else
                                        {
										 cout<<"Int Variable "<<var_name<<" is trying to assign Unrecognised Type of Variable "<<myvar<<endl;
										 exit(0);
                                        }										
										
                                   }								   
						}
		              else if(typeCheck[var_name]==3 || typeCheck[var_name]==4)
					   {
					                if(typeCheck[myvar]==1 || typeCheck[myvar]==2 || typeCheck[myvar]==3 || typeCheck[myvar]==4)
									{
					                  std::stringstream ss(get_variable_value(myvar));
									  ss >> my_floatValue;
                                      $<fval>$ = my_floatValue;	
                                      temp_float = $<fval>$;
                                    }									  
					                else if(typeCheck[myvar]==5) 
					                    {
										 cout<<"Float Variable "<<var_name<<" is trying to assign Character Variable "<<myvar<<endl;
										 exit(0);
                                        }
									else
                                        {
										 cout<<"Float Variable "<<var_name<<" is trying to assign Unrecognised Type of Variable "<<myvar<<endl;
										 exit(0);
                                        }	
	         
				      }
					  else if(typeCheck[var_name]== 5)
					   {
					                if(typeCheck[myvar] == 5)
									{
					                   my_charValue = (get_variable_value(myvar));	
                                       temp_char = my_charValue;
                                    }									  
					                
									else
                                        {
										 cout<<"Char Variable "<<var_name<<" is trying to assign Another Type of Variable "<<myvar<<endl;
										 exit(0);
                                        }	
	         
				      }
		
		      }
           				  
      ;			 
			 
			 
			 
			 
			 

varlist :    varlist ',' vareq {}
            | vareq   {}
            ;	

varlistlong :     varlistlong ',' vareqlong {}
                 | vareqlong   {}
                 ;

varlistfloat :     varlistfloat ',' vareqfloat {}
                 | vareqfloat   {}
                 ;					 

varlistdouble :     varlistdouble ',' vareqdouble {}
                 | vareqdouble   {}
                 ;
				 
varlistchar :      varlistchar ',' vareqchar {}
                 | vareqchar   {}
                 ;				 
					

vareq :      VAR EQ exp            { var_name = $<cval>1; int_value = $<ival>3; value_flag = true; insert_tokentable("int"); }
								   
                  | VAR                  { var_name = $<cval>1; value_flag = false; insert_tokentable("int");}
		          ;
		   
vareqlong :      VAR EQ exp            { var_name = $<cval>1; int_value = $<ival>3; value_flag = true; insert_tokentable("long"); }
								   
               | VAR                  { var_name = $<cval>1; value_flag = false; insert_tokentable("long");}
		       ;

vareqfloat :      VAR EQ expfloat            { var_name = $<cval>1; float_value = $<fval>3; value_flag = true; insert_tokentable("float"); }
								   
                 | VAR                  { var_name = $<cval>1; value_flag = false; insert_tokentable("float");}
		         ;					

vareqdouble :      VAR EQ expfloat            { var_name = $<cval>1; float_value = $<fval>3; value_flag = true; insert_tokentable("double"); }
								   
                 | VAR                  { var_name = $<cval>1; value_flag = false; insert_tokentable("double");}
		         ;				   
		   
vareqchar :      VAR EQ expchar            { var_name = $<cval>1; char_value = temp_char; value_flag = true; insert_tokentable("char"); }
								   
                 | VAR                  { var_name = $<cval>1; value_flag = false; insert_tokentable("char");}
		         ;				   
		   


		   
		   
exp:    exp '+' exp {$<ival>$=$<ival>1+$<ival>3;}
      |	exp '-' exp {$<ival>$=$<ival>1-$<ival>3;}	
	  |	exp '*' exp {$<ival>$=$<ival>1*$<ival>3;}	
	  |	exp '/' exp {
	                  if($<ival>3 == 0)
					    {
						   printf("Can not divide by 0\n");
						  
						 exit(0);
						   
						}
	                 else
					   {
					      $<ival>$=$<ival>1/$<ival>3;
					   }	
					}
	  | '('exp')'  {$<ival>$=$<ival>2;}
      | INTVAL     { $<ival>$=$<ival>1;}
	  |  VAR       {
	  
             		 string myvar = $<cval>1;
		             int my_intValue;
         	
		             if(typeCheck[myvar]==0)
					   {
					     cout<<"In Variable Expression -- Undefined Variable!\n"<<"Variable Name: "<<myvar<<endl;
						 exit(0);  
					   }
					
					 else if(typeCheck[myvar]==1 || typeCheck[myvar]==2) 
					   {
					      std::stringstream ss(get_variable_value(myvar));
					      ss >> my_intValue;
                          $<ival>$ = my_intValue;						
					    }

                     else if(typeCheck[myvar]==3 || typeCheck[myvar]==4) 
					    {
						  cout<<"In Integer Type Variabl ---> trying to assign Float Variable "<<myvar<<endl;
						  exit(0);
                        }
					else if(typeCheck[myvar]==5) 
					    {
						  cout<<"In Integer Type Variabl ---> trying to assign Character Variable "<<myvar<<endl;
						  exit(0);
                        }
					else
                        {
						  cout<<"In Integer Type Variabl ---> trying to assign Unrecognised Type of Variable "<<myvar<<endl;
						  exit(0);
                        }										
										
                       
		
		      }
           		
      ;		
	

	

	
expfloat:       expfloat '+' expfloat {$<fval>$=$<fval>1+$<fval>3;}
           |	expfloat '-' expfloat {$<fval>$=$<fval>1-$<fval>3;}	
	       |	expfloat '*' expfloat {$<fval>$=$<fval>1*$<fval>3;}	
	       |	expfloat '/' expfloat {
	                  if($<fval>3 == 0)
					    {
						   printf("Can not divide by 0\n");
						 exit(0);
						   
						}
	                 else
					   {
					      $<fval>$=$<fval>1/$<fval>3;
					   }	
					}
	       | '('expfloat')'  {$<fval>$=$<fval>2;}
           | FLOATVAL        { $<fval>$=$<fval>1;}
		   | INTVAL          {$<fval>$=$<ival>1;}
		   | VAR      {   
            	       string myvar = $<cval>1;
		               float my_floatValue;
				               
	                    	
		             if(typeCheck[myvar]==0)
					   {
					     cout<<"In Variable Expression -- Undefined Variable!\n"<<"Variable Name: "<<myvar<<endl;
						 exit(0);  
					   }
					 
					 else if(typeCheck[myvar]==1 || typeCheck[myvar]==2 || typeCheck[myvar]==3 || typeCheck[myvar]==4) 
					   {
					     std::stringstream ss(get_variable_value(myvar));
						 ss >> my_floatValue;
                         $<fval>$ = my_floatValue;						
					   }
								
					 else if(typeCheck[myvar]==5) 
					   {
						 cout<<"Float Variable is trying to assign Character Variable "<<myvar<<endl;
					     exit(0);
                       }
				     else
                       {
					     cout<<"Float Variable  is trying to assign Unrecognised Type of Variable "<<myvar<<endl;
						 exit(0);
                       }										
		      }
           		
           ;		

	
expchar :  CHARVAL { $<cval>$=$<cval>1; temp_char = $<cval>$[1];}
          | VAR  {   
            		string myvar = $<cval>1;
				    string my_charValue;
	                    	
		             if(typeCheck[myvar]==0)
					   {
					     cout<<"In Variable Expression -- Undefined Variable!\n"<<"Variable Name: "<<myvar<<endl;
						 exit(0);  
					   }
					  else if(typeCheck[myvar]== 5)
					   {
					     my_charValue = get_variable_value(myvar);	
                         temp_char = my_charValue;
                       }									  
					  else
                        {
						  cout<<"Char Variable "<<var_name<<" is trying to assign Another Type of Variable "<<myvar<<endl;
						  exit(0);
                        }	
	         
				      
		
		      }
           ;	
	



	
	

myprintf : PRINTF      {
                          identifer_type("printf");
			              
						  string myString = (string)$<cval>1;
			
			              string myText = "";
			              string myResultText = "";
			              string myVariableList = "";
			
			              bool fcom = false;
			              int TextCheck = 0;
			              string  myVariable[100];
			              string myVariableValue[100];
			              string myVariableType[100];
			
					      int i=6;
					
					      while(myString[i]!=';')
					        {
					           if(TextCheck>=2)
					                 break;
					           if(myString[i]=='"')
					             {
					                TextCheck++;
						            i++;
						            continue;
					             }
					           if( TextCheck == 1)
					             {					      
						            myText += myString[i];
					             }
					          i++;
					         }
			
			             TextCheck = 0;	
                         i=0;				 
                         while(myString[i]!=';')
					       {
					          if(myString[i]=='"')
					             {
					               TextCheck++;
						           i++;
						           continue;
					             }
					          if( TextCheck >= 2 && myString[i]!=' ')
					             {
                                    if(fcom==true)               					   
						                myVariableList += myString[i];
					                if(myString[i]==',')
					                    fcom = true;
					             }
					          i++;
					       }
					
     					myVariableList[myVariableList.length()-1]='\0';

	     		        i=0; int j=0;
		    	        bool tmpflag = false;
			    
         				while(myVariableList[i]!='\0')
		        		    {
				        	   tmpflag = true;
				               if(myVariableList[i]!= ' ' && myVariableList[i]!= ',')
						          {
						              myVariable[j] += myVariableList[i];
						          }
						       if(myVariableList[i]== ',') 
					           	  {
						              j++;
					              }
						       i++;
				            }
				   
				          int totalVariable;
				          if(tmpflag == false)
				            {
				               totalVariable = 0;
				            }
				          else
				           {
				              totalVariable = j+1;
				           }
				   
				          int varCount = 0;
				          for(i=0;i<totalVariable;i++)
				             {
					            for(int k=1;k<=tokenCount;k++)
	                               {
							          if(myVariable[i]==token_No[k].token_Name)
								        {
								          myVariableValue[i] = token_No[k].token_Value;
								          myVariableType[i] = token_No[k].token_Type;
								          varCount++;
								        }
                                   }
					         }
	
				   
	    			   int  FScounter = 0;
		    		   int variableTrack=0;
				
				   for(i=0;i<myText.length();i++)
				     {
					 
					     if(myText[i]=='%')
						   {	
						       i++;					  
						       if(myText[i]=='d')
							    {
								   if(myVariableType[variableTrack]=="Identifier: Integer")
								    {
									  myResultText+=myVariableValue[variableTrack];
									  variableTrack++;
									  FScounter++;
									}
									else
									{
									  printf("Wrong Formate Specifier!\n");
									  exit(0);
									}
								}
								else if(myText[i]=='f')
								{
								    if(myVariableType[variableTrack]=="Identifier: Floating Point")
								     {
									  myResultText+=myVariableValue[variableTrack];
									  variableTrack++;
									  FScounter++;
									 }
									else
									 {
									  printf("Wrong Formate Specifier!\n");
									  exit(0);
									 }
								 }
								else if(myText[i]=='c')
								{		
								   if(myVariableType[variableTrack]=="Identifier: Character")
								    {
									  myResultText+=myVariableValue[variableTrack];
									  variableTrack++;
									  FScounter++;
									}
									else
									{
									  printf("Wrong Formate Specifier!\n");
									  exit(0);
									}
								}
								else if(myText[i]=='l')
								{
								    i++;
								           if(myText[i]=='d')
							                  {
											     
								                 if(myVariableType[variableTrack]=="Identifier: Long Integer")
								                   {
												     
									                 myResultText+=myVariableValue[variableTrack];
									                 variableTrack++;
													 FScounter++;
									               }
												  else
									                {
									                  printf("Wrong Formate Specifier!\n");
									                  exit(0);
									                }
								              }
								          else if(myText[i]=='f')
								             {
											    if(myVariableType[variableTrack]=="Identifier: Double Floating Point")
								                   {
												   
									                 myResultText+=myVariableValue[variableTrack];
									                 variableTrack++;
													 FScounter++;
									               }
												   else
									                {
									                  printf("Wrong Formate Specifier!\n");
									                  exit(0);
									                }
								             }
								          else
										    {
											   printf("Wrong Formate Specifier!\n");
									           exit(0);
										    }
								
								}
								else
								{
								    printf("Wrong Formate Specifier!\n");
								    exit(0);
								}
						   }
						   
						   
						   else
						       {
							   
							      if(myText[i]=='\\')
								   {
								     i++;
									   if(myText[i]=='n')
									     myResultText+="\n";
									   else if(myText[i]=='t')
									     myResultText+="	"; 
									  else
                                         myResultText+=myText[i];									  
									}
							      else
							         myResultText+=myText[i];
						       }
						   
					 
					 
					 }
					 
					 	
					  if(FScounter != totalVariable)
				        {
				         printf("Number of Format Specifiers or Variables are not Equal!\n");
						 exit(0);
				        }
					 
					      tokenCount++;
			              token_No[tokenCount].token_Name=myText;
			              token_No[tokenCount].token_Type="Constant: String";
			              token_No[tokenCount].token_Value=myResultText;
            }
   
 ;




	
	  
%%



void yyerror(char *s) {
    fprintf(stderr, "%s\n", s);
		
	exit(0);	
}



void identifer_type(string str)
{

                                 if(typeCheck["int"]==0 && str == "int")
		                             {
			                          typeCheck["int"]=6;
			                          tokenCount++;
			                          token_No[tokenCount].token_Name="int";
			                          token_No[tokenCount].token_Type="keyword: Datatype";
			                          token_No[tokenCount].token_Value="no";
									 }
								else if(typeCheck["long"]==0 && str == "long")
		                             {
			                          typeCheck["long"]=6;
			                          tokenCount++;
			                          token_No[tokenCount].token_Name="long";
			                          token_No[tokenCount].token_Type="keyword: Datatype";
			                          token_No[tokenCount].token_Value="no";
									 }
								else if(typeCheck["float"]==0 && str == "float")
		                             {
			                          typeCheck["float"]=6;
			                          tokenCount++;
			                          token_No[tokenCount].token_Name="float";
			                          token_No[tokenCount].token_Type="keyword: Datatype";
			                          token_No[tokenCount].token_Value="no";
									 }
                               else if(typeCheck["double"]==0 && str == "double")
		                             {
			                          typeCheck["double"]=6;
			                          tokenCount++;
			                          token_No[tokenCount].token_Name="double";
			                          token_No[tokenCount].token_Type="keyword: Datatype";
			                          token_No[tokenCount].token_Value="no";
									 }
                               else if(typeCheck["char"]==0 && str == "char")
		                             {
			                          typeCheck["char"]=6;
			                          tokenCount++;
			                          token_No[tokenCount].token_Name="char";
			                          token_No[tokenCount].token_Type="keyword: Datatype";
			                          token_No[tokenCount].token_Value="no";
									 }
                               else if(typeCheck["printf"]==0 && str == "printf")
		                             {
			                          typeCheck["printf"]=6;
			                          tokenCount++;
			                          token_No[tokenCount].token_Name="printf";
			                          token_No[tokenCount].token_Type="Keyword: Function";
			                          token_No[tokenCount].token_Value="no";
			                         }
                              else if(typeCheck["return"]==0 && str == "return")
		                            {
			                         typeCheck["return"]=6;
			                         tokenCount++;
			                         token_No[tokenCount].token_Name="return";
			                         token_No[tokenCount].token_Type="Keyword";
			                         token_No[tokenCount].token_Value="no";
			                        }	
                              else if(typeCheck["main"]==0 && str == "main")
		                           { 
			                        typeCheck["main"]=6;
			                        tokenCount++;
			                        token_No[tokenCount].token_Name="main";
			                        token_No[tokenCount].token_Type="Identifier: Function";
			                        token_No[tokenCount].token_Value="no";
			                       }
		                      else if(typeCheck["void"]==0 && str == "void")
			                  	   {
					                typeCheck["void"]=6;
			 		                tokenCount++;
			 		                token_No[tokenCount].token_Name="void";
			 		                token_No[tokenCount].token_Type="Keyword: Datatype";
			 		                token_No[tokenCount].token_Value="no";
			  		               }								   
    
}




void insert_tokentable(string str1)
{
                                  if(str1=="int")
								  {
								     var_pos = 1;
								      if(value_flag==true)
									    {
                                          std::stringstream ss;
                                          ss << int_value;
                                          ss >> var_value;
									    }
									  else
									      var_value = "no";
									  
									 var_type = "Identifier: Integer";
								  }
								  else if(str1=="long")
								  {
								   var_pos = 2;
                                    if(value_flag==true)
									    {
                                          std::stringstream ss;
                                          ss << int_value;
                                          ss >> var_value;
									    }
									  else
									      var_value = "no";
									 var_type = "Identifier: Long Integer";
								   }
								  else if(str1=="float")
								   {
								    var_pos = 3;
                                    if(value_flag==true)
									    {
                                          std::stringstream ss;
                                          ss << float_value;
                                          ss >> var_value;
									    }
									  else
									      var_value = "no";
									var_type = "Identifier: Floating Point";
								   }
								   else if(str1=="double")
								   {
								    var_pos = 4;
								    if(value_flag==true)
									    {
                                          std::stringstream ss;
                                          ss << float_value;
                                          ss >> var_value;
									    }
									  else
									      var_value = "no";
									 var_type = "Identifier: Double Floating Point";
								   }
								   else if(str1=="char")
								   {
								   var_pos = 5;
								   if(value_flag==true)
									    {
                                          std::stringstream ss;
                                          ss << char_value;
                                          ss >> var_value;
									    }
									  else
									      var_value = "no";
									var_type = "Identifier: Character";
								   }

                                    
								  if(typeCheck[var_name]==0)
		                             {
			                          typeCheck[var_name]=var_pos;
			                          tokenCount++;
									  token_No[tokenCount].token_Name = var_name;
			                          token_No[tokenCount].token_Type=var_type;
			                          token_No[tokenCount].token_Value=var_value;

									 }
									 
									else
									 {
									    cout<<"Duplicate Variable! \n"<<"Variable Name: "<<var_name<<endl;
										
										exit(0);
									 }

}




void   update_tokentable(string str2)
{
                               if(str2=="int" || str2 == "long")
								  {
								     std::stringstream ss;
                                     ss << int_value;
                                     ss >> var_value;  
								  }
							   else if(str2=="float" || str2=="double")
								  {
								     std::stringstream ss;
                                     ss << float_value;
                                     ss >> var_value;   
								  }
							  else if(str2=="char")
								   {
								     std::stringstream ss;
                                     ss << char_value;
                                     ss >> var_value;  
								   }

                     for(int k=1; k<=tokenCount; k++)
	                       {						  
						      if(var_name == token_No[k].token_Name )
							    {								 
						   		 token_No[k].token_Value = var_value;								
								 break;
								}
						   }
}


string get_variable_value(string myvar)
{
    string myvalue="";
                   for(int k=1; k<=tokenCount; k++)
	                       {						  
						      if( myvar == token_No[k].token_Name )
							    {								 
						   		 myvalue=token_No[k].token_Value;								
								 break;
								}
						   }
				
                    if(myvalue == "no")
                      {
					     cout<<"In Variable Expression a NULL valued variable!\n"<<"Variable Name: "<<myvar<<endl;
						 exit(0);
                       }

              return myvalue;					   
}


int main(int argc, char** argv){
    typeCheck["auto"] = typeCheck["break"] = typeCheck["case"] = typeCheck["char"] = typeCheck["const"] = typeCheck["continue"] = typeCheck["default"] = typeCheck["do"] = typeCheck["double"] = typeCheck["else"] = typeCheck["enum"] = typeCheck["extern"] = typeCheck["float"] = typeCheck["for"] = typeCheck["goto"] = typeCheck["if"] = typeCheck["int"] = typeCheck["long"] = typeCheck["register"] = typeCheck["return"] = typeCheck["short"] = typeCheck["signed"] = typeCheck["sizeof"] = typeCheck["static"] = typeCheck["struct"] = typeCheck["switch"] = typeCheck["typedef"] = typeCheck["union"] = typeCheck["unsigned"] = typeCheck["void"] = typeCheck["volatile"] = typeCheck["while"] = typeCheck["main"] = typeCheck["printf"] = 0;

   	yyin=fopen(argv[1],"r");

    yyparse();
	   
	printf("\nToken\tName\t\t\tType\t\t\tValue\n\n");
	for(int i=1;i<=tokenCount;i++)
	{
      cout<<" "<<i<<"\t"<<token_No[i].token_Name<<"\t\t"<<token_No[i].token_Type<<"\t\t"<<token_No[i].token_Value<<"\n"<<endl;
	}  
	   
	fclose(yyin);
	
	getchar();
	
	return 0;
}