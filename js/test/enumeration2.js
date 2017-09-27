//#include ../cfb.js
cfb.Default.Function.returnAsArgument = cfb.False;
var mod = new CfModule('enumeration2', 'ns');
var cls = mod.addCls('cls');
cls.addEnumeration('MySize { mz1, mz2, mz3 }');
cls.namespace = 'csns';
cls.functions = [];
cls.addFunc('Func', 'csns.cls.MySize').addArg('Arg', 'csns.cls.MySize');
cfb.build(mod, 'y:/cfb-git/cs', 'y:/cfb-git/templates', cfb.Templates.tp_cs2010, cfb.False, cfb.False, null, null);
cls.namespace = 'javans';
cls.functions = [];
cls.addFunc('Func', 'javans.cls.MySize').addArg('Arg', 'javans.cls.MySize');
cfb.build(mod, 'y:/cfb-git/java', 'y:/cfb-git/templates', cfb.Templates.tp_java, cfb.False, cfb.False, null, null);
cls.namespace = 'qtns';
cls.functions = [];
cls.addFunc('Func', 'qtns.cls.MySize').addArg('Arg', 'qtns.cls.MySize');
cfb.build(mod, 'y:/cfb-git/qt', 'y:/cfb-git/templates', cfb.Templates.tp_qtWindows, cfb.False, cfb.False, null, null);
