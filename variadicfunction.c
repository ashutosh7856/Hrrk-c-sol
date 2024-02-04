
int  sum (int count,...) {
    va_list ptr;
    va_start(ptr, count);
    
    int sum =0;
    for(int i=0; i<count; i++)
    {
        sum += va_arg(ptr, int);
    }
    va_end(ptr);
    return sum;
}

int min(int count,...) {
    va_list ptr;
    va_start(ptr, count);
    
    int min = va_arg(ptr, int);
    for(int i=1;i<count;i++)
    {
        int value = va_arg(ptr, int);
        if(min>value) 
            min = value;
    }
    va_end(ptr);
    return min;    
}

int max(int count,...) {
    va_list ptr;
    va_start(ptr, count);
    
    int max = va_arg(ptr, int);
    
    for(int i=1;i<count;i++)
    {
        int value = va_arg(ptr, int);
        if(max<value){
            max = value;
        }
    }
    va_end(ptr);
    return max;
}

