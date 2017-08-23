
char chars[]={'+','-','*','(',')'}; //the array whose elements are to be deleted

for(unsigned int i=0; i<strlen(chars) ;++i) {
          a.erase(remove(a.begin(),a.end(),chars[i]),a.end());  //erasing elements of char[i] from string-a
}
