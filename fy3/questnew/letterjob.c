int accept_object(object who, object ob)
{
 object silk;
 if(ob->query("pname") != who->query("name")) 
   {
    tell_object(who,query("name") + "说道：这不是你的，没收。\n");
    who->set_temp("nofly",0);
    return 1;
   }
 if(who->query("letter") < time())
   {
    tell_object(who,query("name") + "说道：哎，晚了，你来晚了！\n");
    who->set_temp("nofly",0);
    return 1;
   }
 if(ob->query("toname") == query("name"))
  {
   command("say 感谢这位远道把密函送来，这是给你的回函,切记要保管好！！\n");
   who->set_temp("nofly",0);
   silk = new("/d/dali/obj/huihan");
   silk->set("pname",who->query("name"));
   silk->move(who);
   return 1;
  }
 tell_object(who,query("name") + "说道：这不是我想要的。\n");
 return 0;
}