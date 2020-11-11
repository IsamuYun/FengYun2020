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
		write("请重新输入您的英文名字)？");
		input_to("confirm_id", ob);
		return;
	}	

	if( yn[0]!='y' && yn[0]!='Y' ) {
		write("请重新输入您的英文名字：");
		input_to("get_id", ob);
		return;
	}
            display();
         write(YEL"目前选择：\n"NOR);
         write(HIW"您的代号     : "NOR);
         input_to((:a:),this_player());
         return 1;
        }
         return notify_fail("你已经填写过注册单。\n"); 
 }
void display()
{
     write(CLR"\n");
   write(HIY"                     【"+MUD_NAME+"注册单】                  \n"NOR);
     write("\n");
}
private void a(string arg, string register)
{
   register = "代号     : "+arg+"\n";
   this_player()->add_temp("register",register);
   write(HIW"您的昵称     : "NOR);
   input_to((:b:),this_player(),register);
}
private void b(string arg, string register)
{
   register = "昵称     : "+arg+"\n";
   this_player()->add_temp("register",register);
   write(HIW"真实姓名     : "NOR);
   input_to((:c:),this_player());
}
private void c(string arg, string register)
{
   register = "姓名     : "+arg+"\n";
   this_player()->add_temp("register",register);
   write(HIW"联系地址     : "NOR);
   input_to((:d:),this_player());
}
private void d(string arg, string register)
{
   register = "联系地址     : "+arg+"\n";
   this_player()->add_temp("register",register);
   write(HIW"工作单位/学校: "NOR);
   input_to((:e:),this_player());
}
private void e(string arg, string register)
{
   register = "工作单位/学校: "+arg+"\n";
   this_player()->add_temp("register",register);
   write(HIW"电子信箱: "NOR);
   input_to((:f:),this_player());
}
private void f(string arg, string register)
{
   register = "电子信箱: "+arg+"\n";
   this_player()->add_temp("register",register);
  write(HIW"联系电话: "NOR);
   input_to((:g:),this_player());
}
private void g(string arg, string register)
{
   string table;
   this_player()->set("register",1);
   register = "联系电话: "+arg+"\n";
   this_player()->add_temp("register",register);
   table =  this_player()->query_temp("register"); 
   this_player()->delete_temp("register");
   write_file("/log/doc/register/"+this_player()->query("id"),table,1);
   write("◇设置一切正确。\n");
}
int help(object me)
{
        write(@HELP
指令格式 : register

为了保障您的合法权利不受到侵害，请认真注册此注册单，如有
问题我们会帮助您及时解决。（例如您的密码丢失，我们可以根
据你所注册资料核对是否属实，可以帮助您及时恢复）。
HELP
    );
    return 1;
}
