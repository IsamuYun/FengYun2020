#pragma save_binary
mapping pwd_mapping=([]);
int main(string id,string event,string input_password)
{
	string password,id_in_file,id_password,*all_password;
	int i;
	//mapping *temp_pwd_mapping;
        mixed *temp_pwd_mapping1,temp_pwd_mapping2;    
        if(!previous_object(0)||previous_object(0)&&getuid(previous_object(0))!=ROOT_UID) return 0;
        if(!id||!event) return 0;
	
	password=read_file("/data/password/"+sprintf("%c-password",id[0])+".pas");
	if(!password){
	    assure_file("/data/password/"+sprintf("%c-password",id[0])+".pas");
	    if(!write_file("/data/password/"+sprintf("%c-password",id[0])+".pas","guest@#@guest\n",1))
		return 0;
	    password="guest@#@guest\n";
	//ʡȴ���滹Ҫ�ж���û��password_file����ļ����鷳
	} 
	
	all_password=explode(read_file("/data/password/"+sprintf("%c-password",id[0])+".pas"),"\n");
	pwd_mapping=allocate_mapping(sizeof(all_password));
	for(i=0;i<sizeof(all_password);i++){
	    //if(all_password[i][0]=='#'||
	      if(sscanf(all_password[i],"%s@#@%s",id_in_file,id_password)!=2) continue;
		pwd_mapping[id_in_file]= id_password;
	}
	if(event=="check"){
	    if(!pwd_mapping[id]){ write("no pwd_mapping\n");return 0;}
	    if(!input_password) { write("no input_password\n");return 0;}
	    
        if( crypt(input_password,pwd_mapping[id])!=pwd_mapping[id]) {
	    	return 0;
	    }
	    return 1;
	    
	}
	if(event=="delete"){
	    if(!pwd_mapping[id]) return 0;
	    map_delete(pwd_mapping,id);
	    password="";
            //i=sizeof(pwd_mapping);
            //while ((temp_pwd_mapping = each(pwd_mapping,1)) != ([])) {
	    //    password+=temp_pwd_mapping[0]+"@#@"+temp_pwd_mapping[1]+"\n";
            //}
	    //ż������each()����.
	    temp_pwd_mapping1=keys(pwd_mapping);//id
	    temp_pwd_mapping2=values(pwd_mapping);//password
	    for(i=0;i<sizeof(temp_pwd_mapping1);i++){
	            password+=temp_pwd_mapping1[i]+"@#@"+temp_pwd_mapping2[i]+"\n";
	    }
	    assure_file("/data/password/"+sprintf("%c-password",id[0])+".pas");
	    if(!write_file("/data/password/"+sprintf("%c-password",id[0])+".pas",password,1))
	        return 0;
	    return 1;
	}
	if(event=="add"){
	    if(!input_password) return 0;
	    map_delete(pwd_mapping,id);
	    password="";
	    temp_pwd_mapping1=keys(pwd_mapping);//id
	    temp_pwd_mapping2=values(pwd_mapping);//password
	    for(i=0;i<sizeof(temp_pwd_mapping1);i++){
	            password+=temp_pwd_mapping1[i]+"@#@"+temp_pwd_mapping2[i]+"\n";
	    }
	    password+=id+"@#@"+crypt(input_password,0)+"\n";
	    assure_file("/data/password/"+sprintf("%c-password",id[0])+".pas");
	    if(!write_file("/data/password/"+sprintf("%c-password",id[0])+".pas",password,1))
	        return 0;
	    return 1;
	}
	return 0;
}
