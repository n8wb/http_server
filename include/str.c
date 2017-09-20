#include "str.h"

Vector explode(char * quan,char * subject){
	Vector out = NULL;
	char * subj;
	register uint_fast64_t i;                                             
	size_t qlength = strlen(quan);
	size_t slength = strlen(subject);
	subj = (char *)malloc(sizeof(char)*(slength+1));
	strcpy(subj,subject);
	subj[slength] = '\0';
	for(i = 0;i<slength-qlength;i++){
		if(strcompsub(quan,subj,i,qlength)){
			vector_push(&out,substring(subj,0,i));
			subj = substr_f(subj,i);
			i = 0;
			slength = strlen(subj);
		}
	}
	return out;
}

char * substring_f(char * subject,size_t index,size_t length){
	char * out = substring(subject,index,length);
	free(subject);
	return out;
}

char * substr_f(char * subject,size_t index){
	char * out = substr(subject,index);
	free(subject);
	return out;
}

char * itoa(uint32_t num){
	char * characters[10] = {"0","1","2","3","4","5","6","7","8","9"};
	return (num>=10)? concat(itoa(num/10),characters[num%10],FALSE) : characters[num];
}



char* str_reverse(char* str){
	size_t length = strlen(str);
	char * out = (char*)malloc(sizeof(char)*(length+1));
	size_t i = 0;
	for(i = 0;i<length;i++){
		out[i] = str[(length-1)-i];
	}
	out[length] = '\0';
	free(str);
	return out;
}

char* strappend(char s,char * str){
	size_t length = strlength(str);
	char* out = (char*)malloc(sizeof(char)*(length+2));
	register size_t i;
	out[0] = s;
	if(str==NULL){
		out[1] = '\0';
		return out;
	}
	for(i = 1;i<length+2;i++){
		out[i] = str[i-1];
	}
	free(str);
	out[length + 1] = '\0';
	return out;
}

char* stradd(char * str,char s){
	size_t length = strlength(str);
	char* out = (char*)malloc(sizeof(char)*(length+2));
	if(str!=NULL){
		strcpy(out,str);
		free(str);
	}
	out[length + 1] = '\0';
	out[length] = s;
	return out;
}


char getLast(char * str){
	return str[strlen(str)-1];
}

char lastChar(char * str){
	return str[strlen(str)-1];
}

char * substring(char * subject,size_t index,int length){
	if(length<0){
		return substring(subject,index,(strlen(subject) - (index - length)));
	}
	char * out = (char *)malloc(sizeof(char)*(length + 1));
	register uint_fast64_t i;
	for(i = 0;i<length && subject[i+index]!='\0';i++){
		out[i] = subject[i+index];
	}
	out[i] = '\0';
	return out;
}
char * substr_r(char * subject,int index){
	register uint_fast64_t length = strlen(subject);
	char * out;
	register uint_fast64_t i = 0;
	register uint_fast64_t start = length + index;
	out = (char *)malloc(sizeof(char)*(index*-1 + 1));

	while(subject[i+start]!='\0'){
		out[i] = subject[i+start];
		i++;
	}
	out[i] = '\0';
	return out;
}
char * substr(char * subject,int index){
	if(index<0){
		return substr_r(subject,index);
	}
	register uint_fast64_t length = strlength(subject);
	char * out;
	register uint_fast64_t i = 0;
	if(length<index+1){
		return NULL;
	}
	out = (char *)malloc(sizeof(char)*(length-index + 1));
	while(subject[i+index]!='\0'){
		out[i] = subject[i+index];
		i++;
	}
	out[i] = '\0';
	return out;
}

uint_least8_t strcompare(char * str1, char * str2){
	register uint_fast64_t l1 = strlength(str1);
	register uint_fast64_t l2 = strlength(str2);
	register uint_fast64_t i;
	if(l1 != l2){
		return FALSE;
	}
	for(i = 0;i<l1;i++){
		if(str1[i] != str2[i]){
			return FALSE;
		}
	}
	return TRUE;
}

uint_least8_t strcompsub(char * str1,char * str2, size_t index, size_t length){
	register uint_fast64_t l1 = strlen(str1);
	register uint_fast64_t i;
	if(l1 != length){
		return FALSE;
	}
	for(i = index;i<length+index;i++){
		if(str1[i-index] != str2[i]){
			return FALSE;
		}
	}
	return TRUE;
}

size_t strlength(char * str){
	if(str == NULL){
		return 0;
	}
	return strlen(str);
}

char * concat(char * s1, char * s2, uint8_t mem){
	register uint_fast64_t l1 = strlength(s1);
	register uint_fast64_t l2 = strlength(s2);
	size_t length = l1 + l2;
	char * out = (char *)malloc(sizeof(char)*(length+1));
	register uint_fast64_t i;
	for(i = 0;i<l1;i++){
		out[i] = s1[i];
	}
	for(i = 0;i<l2;i++){
		out[i+l1] = s2[i];
	}
	if((mem >> 1)& 1){
		free(s2);
	}
	if((mem & 1)){
		free(s1);
	}
	out[length] = '\0';
	return out;
}

int strpos(char * haystack, char * needle){
	size_t length = strlen(haystack);
	size_t nlength = strlen(needle);
	register uint_fast64_t i;
	if(length == 0||nlength>=length){
		return -1;
	}
	for(i = 0;i<=length-nlength;i++){
		if(haystack[i]==needle[0] && strcompsub(needle,haystack,i,nlength)){
			return i;
		}
	}
	return -1;
}
int indexOfChar(char * haystack, char needle){
	size_t length = strlen(haystack);
	register uint_fast64_t i;
	for(i = 0;i<length;i++){
		if(haystack[i]==needle){
			return i;
		}
	}
	return -1;
}
