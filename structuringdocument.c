#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#define MAX_CHARACTERS 1005
#define MAX_PARAGRAPHS 5

struct word {
    char* data;
};

struct sentence {
    struct word* data;
    int word_count;//denotes number of words in a sentence
};

struct paragraph {
    struct sentence* data  ;
    int sentence_count;//denotes number of sentences in a paragraph
};

struct document {
    struct paragraph* data;
    int paragraph_count;//denotes number of paragraphs in a document
};
int newindex = 0 ; // declared as global index

struct word get_Word(char *text){

    struct word result_word ;

    int characters = 0;
    for(int i=(newindex) ; text[i] != ' ' && text[i] != '.' && text[i] != '\n' && text[i] != 0; i++){characters ++ ;}

    result_word.data = (char*)calloc(characters , sizeof(char)); 


    for(int i=0; i<characters; i++){
        result_word.data[i] = text[(newindex) + i];
    }

   

    for(int i=(newindex); (i + characters + 1)<strlen(text); i++ ){

            if( ('a' <= text[i + characters + 1] && text[i + characters + 1] <= 'z') || ('A' <= text[i + characters + 1] && text[i + characters + 1] <= 'Z' ) ){
               
                (newindex) = i + characters + 1;
                return result_word;
            }
    }

    return result_word ;

}

struct sentence get_Sentence(char *text){
    struct sentence sen ;

    sen.word_count = 1 ;
    for(int i=(newindex); text[i] != '.' && text[i] != '\n' && text[i] != 0; i++){
        if(text[i] == ' '){sen.word_count ++ ;}
    }

    sen.data = (struct word*)calloc(sen.word_count, sizeof(struct word));

    
    for(int i =0; i<sen.word_count; i++){
        sen.data[i] = get_Word(text );
    }

    return sen;
}

struct paragraph get_Paragraph(char *text){
    struct paragraph para ;

    para.sentence_count = 0;
    for(int i=(newindex); text[i] != '\n' && text[i] != 0  ; i++){
        if(text[i] == '.'){para.sentence_count ++ ;}
    }

    para.data = (struct sentence*)calloc(para.sentence_count, sizeof(struct sentence));

    
    for(int i=0; i<para.sentence_count ; i++){
        para.data[i] = get_Sentence(text );
    }
    

    return para;
}

struct document get_document(char* text) {

    struct document doc ;
    doc.paragraph_count = 1;
    for(int i =0 ; i<(strlen(text)) ; i++){ doc.paragraph_count ++ ;}

    doc.data = (struct paragraph*)calloc(doc.paragraph_count , sizeof(struct paragraph) ) ;

   

    for(int i=0; i<doc.paragraph_count; i++){
        doc.data[i] = get_Paragraph(text);
    }

    return doc ;

}


struct word kth_word_in_mth_sentence_of_nth_paragraph(struct document Doc, int k, int m, int n) {
    return Doc.data[n-1].data[m-1].data[k-1] ;
}

struct sentence kth_sentence_in_mth_paragraph(struct document Doc, int k, int m) { 
    return Doc.data[m-1].data[k-1] ;
}

struct paragraph kth_paragraph(struct document Doc, int k) {
    return Doc.data[k-1] ;
}
