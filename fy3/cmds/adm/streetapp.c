#define __ROOMDIR__ "/p2/fystreet/"
inherit F_CLEAN_UP;
int main()
{  string filename,file;
   object room,me;
   int i;
   me=this_player();room=environment(me);
   if(room->query("exits/north")) return notify_fail("�����Ѿ���·�ˣ���\n");
   if(room->query("coor/z")!=0) return notify_fail("��ֻ����չ���ƽ֣���\n");
   if(room->query("coor/x")!=50) return notify_fail("��ֻ����չ���ƽ֣���\n");
   if(room->query("coor/y")<30) return notify_fail("��ֻ����չ���ƽ֣���\n");
   i=(room->query("coor/y")-20)/10;
filename=__ROOMDIR__"street"+(string)i+".c";file=read_file(filename);
   file=replace_string(file,"#define ID "+(string)i,"#define ID "+(string)(i+1));
   filename=__ROOMDIR__"street"+(string)(i+1)+".c";write_file(filename,file,1);i++;
filename=__ROOMDIR__"street000.c";file=read_file(filename);
   file=replace_string(file,"#define ID 100","#define ID "+(string)(i)+"00");
   filename=__ROOMDIR__"street"+(string)i+"00.c";write_file(filename,file,1);
   file=replace_string(file,"#define ID "+(string)(i)+"00","#define ID "+(string)(i)+"01");
   filename=__ROOMDIR__"street"+(string)i+"01.c";write_file(filename,file,1);
filename=__ROOMDIR__"street"+(string)(i-1)+".c";file=read_file(filename);
   file=replace_string(file,"//","");write_file(filename,file,1);
   message_vision("$N���߼а˺�������һ��ѿ�Ƭ������һ�ӣ��������Ľ������Ľ�����\n",me);
   write("3 file(s) copied. 1 file(s) modified.\n");
   message_vision("�������Ļ������һƬ�յأ����ƽֿ������ֳ���һЩ��\n",me);
return 1;
}
