// help.c
// created by bobo ,98.8.20
#include <ansi.h>
void display();
private void a(string arg, string register);
private void b(string arg, string register);
private void c(string arg, string register);
private void d(string arg, string register);
private void e(string arg, string register);
private void f(string arg, string register);
private void g(string arg, string register);
int main(object me)
{
        if(!me->query("register")) {
         if( yn=="" ) {
		write("��������������Ӣ������)��");
		input_to("confirm_id", ob);
		return;
	}	

	if( yn[0]!='y' && yn[0]!='Y' ) {
		write("��������������Ӣ�����֣�");
		input_to("get_id", ob);
		return;
	}
            display();
         write(YEL"Ŀǰѡ��\n"NOR);
         write(HIW"���Ĵ���     : "NOR);
         input_to((:a:),this_player());
         return 1;
        }
         return notify_fail("���Ѿ���д��ע�ᵥ��\n"); 
 }
void display()
{
     write(CLR"\n");
   write(HIY"                     ��"+MUD_NAME+"ע�ᵥ��                  \n"NOR);
     write("\n");
}
private void a(string arg, string register)
{
   register = "����     : "+arg+"\n";
   this_player()->add_temp("register",register);
   write(HIW"�����ǳ�     : "NOR);
   input_to((:b:),this_player(),register);
}
private void b(string arg, string register)
{
   register = "�ǳ�     : "+arg+"\n";
   this_player()->add_temp("register",register);
   write(HIW"��ʵ����     : "NOR);
   input_to((:c:),this_player());
}
private void c(string arg, string register)
{
   register = "����     : "+arg+"\n";
   this_player()->add_temp("register",register);
   write(HIW"��ϵ��ַ     : "NOR);
   input_to((:d:),this_player());
}
private void d(string arg, string register)
{
   register = "��ϵ��ַ     : "+arg+"\n";
   this_player()->add_temp("register",register);
   write(HIW"������λ/ѧУ: "NOR);
   input_to((:e:),this_player());
}
private void e(string arg, string register)
{
   register = "������λ/ѧУ: "+arg+"\n";
   this_player()->add_temp("register",register);
   write(HIW"��������: "NOR);
   input_to((:f:),this_player());
}
private void f(string arg, string register)
{
   register = "��������: "+arg+"\n";
   this_player()->add_temp("register",register);
  write(HIW"��ϵ�绰: "NOR);
   input_to((:g:),this_player());
}
private void g(string arg, string register)
{
   string table;
   this_player()->set("register",1);
   register = "��ϵ�绰: "+arg+"\n";
   this_player()->add_temp("register",register);
   table =  this_player()->query_temp("register"); 
   this_player()->delete_temp("register");
   write_file("/log/doc/register/"+this_player()->query("id"),table,1);
   write("������һ����ȷ��\n");
}
int help(object me)
{
        write(@HELP
ָ���ʽ : register

Ϊ�˱������ĺϷ�Ȩ�����ܵ��ֺ���������ע���ע�ᵥ������
�������ǻ��������ʱ������������������붪ʧ�����ǿ��Ը�
������ע�����Ϻ˶��Ƿ���ʵ�����԰�������ʱ�ָ�����
HELP
    );
    return 1;
}
