 String split_res [5];

void split_string(String data) {
 int i = 0;

 int val = data.indexOf(':');

 while(val != -1) {
   split_res[i] = data.substring(0,val-1);
   data = data.substring(val+1);
   i++;
   int val = data.indexOf(':');
 }

 split_res[i] = data;
}

void colorparse(String colordata) {
  
}

void c_set(String *tail) {

}
