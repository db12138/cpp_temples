
class Solution {
public:
    void replaceSpace(char *str,int length) {
        for(int i=0;i<strlen(str);)
        {
            if(str[i]!= ' ')
                i++;
            else{
                for(int j=strlen(str);j>i;j--)
                    str[j+2] = str[j];
                str[i++] = '%';
                str[i++] = '2';
                str[i++] = '0';
            }
        }
    }
};
