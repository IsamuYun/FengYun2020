int accept_object(object who, object ob)
{
 object silk;
 if(ob->query("pname") != who->query("name")) 
   {
    tell_object(who,query("name") + "˵�����ⲻ����ģ�û�ա�\n");
    who->set_temp("nofly",0);
    return 1;
   }
 if(who->query("letter") < time())
   {
    tell_object(who,query("name") + "˵�����������ˣ��������ˣ�\n");
    who->set_temp("nofly",0);
    return 1;
   }
 if(ob->query("toname") == query("name"))
  {
   command("say ��л��λԶ�����ܺ����������Ǹ���Ļغ�,�м�Ҫ���ܺã���\n");
   who->set_temp("nofly",0);
   silk = new("/d/dali/obj/huihan");
   silk->set("pname",who->query("name"));
   silk->move(who);
   return 1;
  }
 tell_object(who,query("name") + "˵�����ⲻ������Ҫ�ġ�\n");
 return 0;
}