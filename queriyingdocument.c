include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<assert.h>
#define MAX_CHARACTERS 1005
#define MAX_PARAGRAPHS 5


char* kth_word_in_mth_sentence_of_nth_paragraph(char**** document, int k, int m, int n) 
{
    return document[n-1][m-1][k-1];
}



char** kth_sentence_in_mth_paragraph(char**** document, int k, int m) 
{ 
    return document[m-1][k-1];
}

char*** kth_paragraph(char**** document, int k) 
{
    return document[k-1];
}

char* get_word(char* text, int start, int end) 
{
    
    int w_indx = 0 ;

    char* word = calloc( end - start + 2, sizeof(char) ) ;
    
    for( int i = start; i <= end; i++ )
    {
        
        word[w_indx] = text[i] ;
        
        w_indx++ ;
        
    }
    
    word[w_indx] = '\0' ;

    return word ;
    
}
char** get_sentence(char* text, int start, int end) 
{
    
    char** sentence ;
    
    int word_cntr   = 1     ;
    int i           = start ;
    int s_indx      = 0     ;
    int w_start     = start ;
    
    for( int j = start; j <= end; j++ )
    {
        
        if( text[j] == ' ' )
        {
            word_cntr++ ;
        }
        else 
        {
        
        }
        
    }
    
    sentence = calloc( word_cntr, sizeof(char *) ) ;
  
    for( i = start; i <= end; i++ )
    {
        
        if( text[i] == ' ' )
        {
            sentence[s_indx] = get_word( text, w_start, i - 1 ) ;
            
            s_indx++ ;
            w_start = i + 1 ;
            
        }
        else 
        {
        
        }
        
    }
    sentence[s_indx] = get_word( text, w_start, i - 1 ) ;
  
    return sentence ;
    
}
char*** get_paragraph(char* text, int start, int end) 
{
    
    char*** paragraph ;
   
    int sentence_cntr   = 1     ;
    int i               = start ;
    int p_indx          = 0     ;
    int s_start         = start ;
    
    for( int j = start; j <= end; j++ )
    {
        
        if( text[j] == '.' )
        {
            sentence_cntr++ ;
        }
        else 
        {
        
        }
        
    }
    
    paragraph = calloc( sentence_cntr, sizeof(char **) ) ;
    
    for( i = start; i <= end; i++ )
    {
        
        if( text[i] == '.' )
        {
            
            paragraph[p_indx] = get_sentence( text, s_start, i - 1 ) ;
            
            p_indx++ ;
            s_start = i + 1 ;
            
        }
        else 
        {
        
        }
        
    }
    
    return paragraph ;
    
}

char**** get_document(char* text) 
{

    char **** docx ;
    
    int paragraph_cntr  = 1 ;
    int i               = 0 ;
    int d_indx          = 0 ;
    int p_start         = 0 ;
    
    for( int j = 0; text[j] != '\0'; j++ )
    {
        
        if( text[j] == '\n' )
        {
            paragraph_cntr++ ;
        }
        else 
        {
        
        }
        
    }
        
    docx = calloc( paragraph_cntr, sizeof(char***) ) ;

    for( i = 0; text[i] != '\0'; i++ )
    {
        
        if( text[i] == '\n' )
        {
            
            docx[d_indx] = get_paragraph( text, p_start, i - 1 ) ;
            
            d_indx++ ;
            
            p_start = i + 1 ;
            
        }
        else 
        {
        
        }
        
    }
    docx[d_indx] = get_paragraph( text, p_start, i - 1 ) ;
    
    return docx ;

}
