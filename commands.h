void split_string(String data) {
 String split_res[];
 int i = 0;

 int val = indexOf(':');

 while(val != -1) {
   split_res[i] = data.substring(0,val-1);
   data = data.substring(val+1);
   i++;
   int val = indexOf(':');
 }

 split_res[i] = data;
}


void c_set(String *tail) {

}
