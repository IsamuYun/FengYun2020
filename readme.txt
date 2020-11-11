1.feature/damage 攻防修正，增加攻防加成
2.combatd,logind修改，种族添加，战斗计算方式调整。
3.preload去除upgraded，
4./cmds/usr/upgrade,hp,score,distribute修改，增加升级命令，HP,SCORE的命令调整显示方式，DISTRIBUTE增加手动加点，不封顶。
5./cmds/std/learn,research,practice，study修改,夫妻learn去除，学习耗费金钱，学习技能上限和等级挂钩，practice,study上限改为学习的1/2
6./obj/money/thousand-gold去除
7./cmd/usr/set 以及help修改增加pk保护开关。
8.删除bang 删除玩家能创建帮派的功能
9.删除baiyiren身上的学习十字剑法的CODE。
10.reborned暂时禁止重生。
11.biaonpc修改，查猛运镖任务更改先前李一飞任务，奖励为获得GOLD。
13.去除天地阁，狂人帮，百花谷，清风，伏龙，XLD，黑苗，白苗，LJB，蜀山，华山，血刀。
14.去除BIGTASK数量的额外奖励，TASK奖励不封顶
15.kill修改，去除一些不必要的设置
16./adm/daemons/race/human修改，增加NPC等级，属性定义，以及人物的三围
17.朝廷：yin的黑衣人任务20-50,俸禄添加,去除加入chaoting工作的mark
18.所有门派技能不允许practice,
19./feature/attibute 的属性修改
20.每一个skills添加belong()函数，代表该技能属于哪个门派，
21.check命令的修改，技能的状态定义set_temp("技能PFM的英文")，PFM加入熟练
22.更改了三清符咒的名字，把用"-"的都去除
23.增加sanqing_drug的condition
24.修改look状态显示
25.去掉一些master,kumei,yuan,master yu,duanyu,master duan,wangyuyan,master guanyin,huangshan 2 masters,master yu,
master renci,master nangong,master ding,master can,master xing,shaolin master,master xie,master shenshui,master bai
baiyumo,cxq,ximen,laodao,xiao,lan,tieshao,xuerui
26.i,look,duanzao,lianzhi,score命令修改，配合武器装备系统,damage,equip
27.zhuge.heiyiren,songxin,diao fish,调整
28.combatd中出招计算调整,tiejob调整，带双倍经验道具。
29.成长任务标签为longstory 目前只完成标签到5。i



门派特色:
1.朝廷：
基础技能 dodge ,force,literate(增加yuhuan,zhuifeng,bajian命中),move,sword,unarmed,parry,
辅助技能 leadership(增加bajian的伤害),strategy(增加yuhuan,zhuifeng的伤害)
初级技能 changquan      yuhuan            多段攻击     增加最后一击出招率    
                        zhuifeng          单段攻击     增加100点伤害
	 liuyun-steps   xingyunliushui    加临时闪避   增加成功率      自己
	 jingxinforce   calm              加临时定力   增加成功率      自己
高级技能 danei-sword    bajian            降低闪避     增加有效时间
特色：周俸禄，汉族，召唤大内（BUSY时不能召唤）,arrest调整为两技能最低技能/10必须不小于对方level
        属于物理攻击门派

2.白云：
基础技能 dodge,force,literate(增加tianwaifeixian命中),move,sword,parry,
辅助技能 daode,            jinganghuti    加临时耐力   增加成功率          自己
初级技能 feixian-sword     tianwaifeixian 单段攻击     增加命中，伤害
	 feixian-steps     tianwaifeixian 多段攻击     增加攻击次数
	 jingyiforce       speedup        加临时速度   增加成功率
高级技能 feixianforce                     增加tianwaifeixian的伤害
特色  preach,汉，攻防俱佳，属于物理攻击门派

3.武当：force,literate(增加命中）move,sword,unarmed,spells.
初级技能 taijiforce        huixin         加临时运气   增加成功率      自己
	 three-sword       sancai         组队多段     增加200点伤害
                           nianzijue      busy技能     增加busy时间，略微增加成功几率
	 qixing            jixing         加临时伤害       增加成功率，有效时间
                           hanxing        加临时物理防御   增加成功率，有效时间
高级技能 taiji             luanhuanjue    追加攻击     增加攻击次数
特色   攻击低，能为他人增加临时属性，BUSY。汉，属于辅助门派。

4.三清：
基础技能  dodge,force,magic,spells,move,literate
辅助技能  taoism                          增加法术绝招伤害
初级技能  gouyee            concentrate   增加成功率             
	  scratmancy                 
          scratching
	  notracesnow       mantianfeixue 增加成功率    
高级技能  necromancy         
特色    回法力，魔法闪避，画坐标，藏，属于辅助门派。


5.大旗：辅助类，吸血  藏
基础技能：dodge,force,literate,unarmed,sword
辅助技能: dormancy	
初级技能：jiayiforce        jiayi          
          ill-quan          qiankun        对手互杀
                            duzhan         单体中毒
	  tie-steps         chansi         降低对手物理闪避和防御   有效时间
高级技能  fy-sword          xixuejian      吸血
特色：吸血，藏
，嫁衣，毒



6.大昭：物理类  反弹  防御最强   藏 
基础技能:unarmed,staff,force,parry,literate,iron-cloth
辅助技能:buddhism
初级技能:cloudstaff         longxianyuye    单段攻击
			    siqijinlong     多段攻击
	 bolomiduo,         roar            增加防御
         jin-gang           daoqiangburu    反弹伤害
高级技能: bloodstrike,      fefawubian      禁药
特色:反弹，防御最强，藏
   
7.大理：速攻类，有俸禄 速度快，暴击率高  白  
8.金钱：速攻类，带毒  速度快    白
9.铁雪：速攻类  攻防俱佳       白

10.蝙蝠：辅助类，带毒  满  
11.魔教：物理类  8段攻击   满
12.兴国：医生类  恢复法术  满

13.帝王：法术类  随身商店   苗 
14.移花：法术类，法术  苗
15.白水：法术类，高体  苗

16.万梅：强击类，蒙古
17.天锤：强击类，攻击最强，追加攻击  蒙古
18.圆月：强击类，多段攻击  蒙古
