//#include ../cfb.js
var mod = new CfModule('enumeration0', 'ns');
var cls = mod.addCls('cls');
cls.addEnumeration('MySize { mz1, mz2, mz3 }');
cls.namespace = 'csns';
cls.properties = [];
cls.addProp('PMySize', 'csns.cls.MySize');
cfb.build(mod, 'y:/cfb-git/cs', 'y:/cfb-git/templates', cfb.Templates.tp_cs2010, cfb.False, cfb.False, null, null);
cls.namespace = 'javans';
cls.properties = [];
cls.addProp('PMySize', 'javans.cls.MySize');
cfb.build(mod, 'y:/cfb-git/java', 'y:/cfb-git/templates', cfb.Templates.tp_java, cfb.False, cfb.False, null, null);
cls.namespace = 'qtns';
cls.properties = [];
cls.addProp('PMySize', 'qtns.cls.MySize');
cfb.build(mod, 'y:/cfb-git/qt', 'y:/cfb-git/templates', cfb.Templates.tp_qtWindows, cfb.False, cfb.False, null, null);
