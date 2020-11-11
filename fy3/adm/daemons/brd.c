void create()
{
        seteuid(getuid());

}
int new_x(int x,string dir);
int new_y(int y,string dir);
int new_z(int z,string dir);

void buildroom(object me,int flag,string s_title,string l_title, string dir)
{
mapping pairs = ([
        "north":                "south",
        "south":                "north",
        "east":                 "west",
        "west":                 "east",
        "northup":              "southdown",
        "southup":              "northdown",
        "eastup":               "westdown",
        "westup":               "eastdown",
        "northdown":    	"southup",
        "southdown":    	"northup",
        "eastdown":             "westup",
        "westdown":             "eastup",
        "northeast":    	"southwest",
        "northwest":    	"southeast",
        "southeast":    	"northwest",
        "southwest":    	"northeast",
        "up":                   "down",
        "down":                 "up"
]);

	object env;
	string this_file;
	string my_file;
	string name;
	string c_name,o_name;
	name = (string)me->query("id")+sprintf("%d",time());
//ready to build!!!
//Let's read in the .o file istead
	c_name = base_name(environment(me))+".c";
        o_name = base_name(environment(me))+".o";
	this_file = read_file(o_name);
	this_file = replace_string(this_file,"set(\"exits\", ([",
"set(\"exits\", ([\n"+"\""+dir+"\""+" : __DIR__"+"\""+name+"\",");	
//do NOT change this write_file
        if(!write_file(o_name,this_file,1))
        return;
// change this to write_file2
        if(!write_file(c_name,this_file,1))
        return;
	environment(me)->set("exits/"+dir,"/p/residence/"+name);	
	// now the room we are in is done!
	my_file = read_file("/obj/USER_ROOM.o");
	my_file = replace_string(my_file,
"set(\"exits\", ([",
"set(\"exits\", ([\n"+"\""+pairs[dir]+"\""+" : "+"\""+c_name+"\",");
	my_file= replace_string(my_file,"SHORT_TITLE",s_title);
	 my_file= replace_string(my_file,"LONG_TITLE",l_title);
	my_file= replace_string(my_file,"#define X_COOR 0",
	sprintf("#define X_COOR %d",
	new_x((int)environment(me)->query("coor/x"),dir)));	
        my_file= replace_string(my_file,"#define Y_COOR 0",
        sprintf("#define Y_COOR %d",
        new_y((int)environment(me)->query("coor/y"),dir)));
        my_file= replace_string(my_file,"#define Z_COOR 0",
        sprintf("#define Z_COOR %d",
        new_z((int)environment(me)->query("coor/z"),dir)));
	my_file= replace_string(my_file,"#define R_FLAG 0",
        sprintf("#define R_FLAG %d",flag));
	if(me->query("family/family_name"))
	my_file= replace_string(my_file,"bigwiz7001",
	me->query("family/family_name"));
        my_file= replace_string(my_file,"bigtie7001",
        me->query("id"));
// now we need to write out this file!
// do NOT change this one!
	write_file("/p/residence/"+name+".o",my_file,1);
	write("�ɹ�����\n");
// change this one to write_file2
        write_file("/p/residence/"+name+".c",my_file,1);
	me->add("created_room",1);
	me->save();
}

int new_x(int x, string dir)
{
	switch (dir) {
	case "east" :
        case "eastup" :
        case "eastdown" :
        case "northeast" :
        case "southeast" :	return x+10;
	case "west" :
        case "westdown" :
        case "westup" :
        case "northwest" :
        case "southwest" :	return x-10;

	default: return x;
	}

}
int new_y(int y, string dir)
{
        switch (dir) {
	case "north" :
        case "northup" :
        case "northdown" :
        case "northeast" :
        case "northwest" : return y+10;
        case "south" :
        case "southup" :
        case "southdown" :
        case "southeast" :
        case "southwest" : return y-10;

        default: return y;
        }

}
int new_z(int z, string dir)
{
        switch (dir) {
	case "up" :
        case "northup" :
        case "southup" :
        case "eastup" :
        case "westup" : return z+10;
        case "down" :
        case "eastdown" :
        case "westdown" :
        case "northdown" :
        case "southdown" : return z-10;

        default: return z;
        }

}

int touch_file(string name)
{
if(write_file(name," ",1))
return 1;
else return 0;
}

