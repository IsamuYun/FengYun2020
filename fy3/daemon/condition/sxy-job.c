//sxy-job.c
//xgchen@fy 2002
#include <ansi.h>
mapping *sxy = ({ 
         ([ "sxy":"沉香镇中心","where":"/d/chenxiang/cxcenter"   ]),
          ([ "sxy":"少室阙","where":"/d/songshan/shaoshi"   ]),
         ([ "sxy":"掖门","where":"/d/shaolin/ye2"   ]),
         ([ "sxy":"紫霄宫","where":"/u/wudang/zhixiao"   ]),
          ([ "sxy":"武当观","where":"/u/wudang/wudang"   ]),
         ([ "sxy":"白梅阁","where":"/d/wanmei/center"   ]),
         ([ "sxy":"山庄后院","where":"/d/wanmei/backyard"   ]),
         ([ "sxy":"枯梅堂","where":"/d/wanmei/meidang"   ]),
         ([ "sxy":"八角街","where":"/u/guanwai/octo15"   ]),              
         ([ "sxy":"八角街","where":"/u/guanwai/octo14"   ]),
         ([ "sxy":"八角街","where":"/u/guanwai/octo13"   ]),
         ([ "sxy":"八角街","where":"/u/guanwai/octo12"   ]),
         ([ "sxy":"八角街","where":"/u/guanwai/octo11"   ]),
        ([ "sxy":"警世书局","where":"/d/fy/jssju"   ]),
         ([ "sxy":"普生堂","where":"/d/fy/pusheng"   ]),
         ([ "sxy":"风云南城门","where":"/d/fy/sgate"   ]),
         ([ "sxy":"风云北城门","where":"/d/fy/ngate"   ]),
         ([ "sxy":"武当前院","where":"/u/wudang/wudang1"   ]),
         ([ "sxy":"千银当铺","where":"/d/fy/qianyin"   ]),
         ([ "sxy":"方舟","where":"/d/tieflag/ark"   ]),
         ([ "sxy":"留云馆","where":"/d/tieflag/cloudinn"   ]),
         ([ "sxy":"青室","where":"/d/tieflag/cynroom"   ]),
         ([ "sxy":"平台","where":"/d/tieflag/platform"   ]),
         ([ "sxy":"碧蓝海边","where":"/d/tieflag/seaside"   ]),
         ([ "sxy":"观月顶","where":"/d/tieflag/moonding"   ]),
         ([ "sxy":"黑暗狱","where":"/d/death/heian"   ]),
         ([ "sxy":"冥府忠司","where":"/d/death/zong"   ]),
         ([ "sxy":"精致卧房","where":"/d/guanyin/bedroom"   ]),
         ([ "sxy":"百丈泉","where":"/d/huangshan/baizhang"   ]),
         ([ "sxy":"观音石","where":"/d/huangshan/guanyin"   ]),
         ([ "sxy":"桃源亭","where":"/d/huangshan/taoyuan"   ]),
         ([ "sxy":"清凉台","where":"/d/huangshan/qingliang"   ]),
      ([ "sxy":"拉哈苏","where":"/d/laowu/laowu"   ]),
      ([ "sxy":"瀑布前","where":"/d/oldpine/waterfall"   ]),
      ([ "sxy":"松树林","where":"/d/oldpine/pine2"   ]),
      ([ "sxy":"白衣殿","where":"/d/shaolin/baiyi"   ]),
        ([ "sxy":"般若堂","where":"/d/shaolin/banruo"   ]),
         ([ "sxy":"褂搭寮","where":"/d/shaolin/guagua"   ]),
        ([ "sxy":"陛石阶","where":"/d/shaolin/lishi"   ]),
        ([ "sxy":"习技堂","where":"/d/shaolin/xiji"   ]),
         ([ "sxy":"养性堂","where":"/d/shaolin/yangxing"   ]),
        ([ "sxy":"方丈","where":"/d/shaolin/fang"   ]),
         ([ "sxy":"天贶殿","where":"/d/daimiao/tiankuang" ]),
         ([ "sxy":"铜亭铁塔","where":"/d/daimiao/tongting"]),
         ([ "sxy":"胡家当铺","where":"/d/chenxiang/dangpu"]),
         ([ "sxy":"破旧长城","where":"/u/quicksand/oldgreatwall"]),
         ([ "sxy":"丰号布铺","where":"d/songshan/bupu"]),
         ([ "sxy":"塞外风光","where":"/u/quicksand/saiwai2"]),
        ([ "sxy":"千佛殿","where":"/d/shaolin/qianfe"   ]),
      ([ "sxy":"前花园","where":"/d/qianjin/garden"   ]),
       ([ "sxy":"断桥踏板","where":"/d/qianjin/taban"   ]),
      ([ "sxy":"葡萄沟","where":"/d/xj/butao"   ]),
      ([ "sxy":"没有名字的地方","where":"/d/xj/wuming"   ]),
      ([ "sxy":"风铃梅枝门","where":"/d/wanmei/gate"   ]),
     ([ "sxy":"枯梅堂","where":"/d/wanmei/meidang"   ]),
      ([ "sxy":"刑房","where":"/u/chuenyu/tortureroom"   ]),
      ([ "sxy":"石屋","where":"/u/ghost/house3"   ]),
      ([ "sxy":"日朝园","where":"/u/palace/palace_gate"   ]),
      ([ "sxy":"死谷","where":"/u/quicksand/valley"   ]),
      ([ "sxy":"世外桃源","where":"/u/resort/another_sky"   ]),
          ([ "sxy":"配天门","where":"/d/daimiao/peitian"   ]),   
         ([ "sxy":"鹰记商号","where":"/u/guanwai/shop"]),    
         ([ "sxy":"大招寺","where":"/u/guanwai/dazhaotemple"]),    
         ([ "sxy":"丰号布铺","where":"d/songshan/bupu"]),   
                  });
                
mapping query_sxy()
{
        return sxy[random(sizeof(sxy))];
}

int update_condition(object me, int duration)
{
        mapping sxy,sxywhere;
        object ob;
        sxy = this_object()->query_sxy();
        sxywhere = sxy["where"];
   if(duration%6 != 0)
  {
   me->apply_condition("sxy-job", duration - 1);
   return 1;
  }         
   if( duration < 1 )
   {
      tell_object(me, HIB "武林盟主正在招集，先回去领命吧！\n" NOR );           
      me->delete("job/sxy");
      me->set("job/sxy-done",1);   
      return 0;
   }
      tell_object(me, RED "武林盟主有令: 天宗人马在" + sxy["sxy"] + "出现了！请马上去击退！\n" NOR );
        ob = new("/d/xgchen/npc/tianzong");
        ob->set("sxy-name",me->query("id"));
          ob->set("kee",me->query("max_kee")*3);
        ob->set("max_kee",me->query("max_kee")*3);
        ob->set("max_gin",me->query("max_gin")*3);
        ob->set("gin",me->query("max_gin"));
        ob->set("sen",me->query("max_sen"));
        ob->set("max_sen",me->query("max_sen")*3);
        ob->set("eff_gin",me->query("max_gin")*3);
        ob->set("eff_kee",me->query("max_kee")*3);
        ob->set("eff_sen",me->query("max_sen")*3);
        ob->set("force",me->query("max_force"));
        if(me->query("level")>70)
			ob->set("force_factor",random(200)+100);
		else
			ob->set("force_factor",random(100));
			
              ob->set("level", me->query("level"));
                ob->set_skill("force", 300);
                ob->set_skill("move", 300);
                ob->set_skill("dodge", 300);
                ob->set_skill("unarmed", 300);
                ob->set_skill("sword", 300);
                ob->set_skill("parry", 300);
                ob->set_skill("iron-cloth", 500);
                ob->set("str", me->query("str"));
                ob->set("int", me->query("int"));
                ob->set("cor", me->query("cor"));
                ob->set("cps", me->query("cps"));
                ob->set("kar", me->query("kar"));
                ob->set("con", me->query("con"));
                ob->set("spi", me->query("spi"));
      ob->move(sxywhere);
	  	if (me->query("mengzhuauto")-time()>0)
				{
					write("你使用的盟主任务丹发挥功效了.\n");
					me->move(sxywhere);
				}
   me->apply_condition("sxy-job", duration - 1);

   if( duration < 1 )
   {
      tell_object(me, HIB "武林盟主正在招集，快回去领命吧！\n" NOR );
      me->delete("job/sxy");
      me->set("job/sxy-done",1);        
      return 0;
   }
   return 1;
}

