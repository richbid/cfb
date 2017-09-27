//#include ../cfb.js
cfb.Default.Module.javaVersion = '8';
var mod = new CfModule('lambda0', 'ns');
var cls = mod.addCls('cls');
cls.addProp('PBool', cfb.Types.vt_bool);
var proc = cls.addProc('Propc');
proc.addSubFunction('step1');
proc.addSubFunction('step2');
proc.addSubFunction('step3');
var func = cls.addFunc('Func', cfb.Types.vt_bool);
func.addSubFunction('step1');
func.addSubFunction('step2');
func.addSubFunction('step3');
cls.namespace = 'csns';
cfb.build(mod, 'y:/cfb-git/cs', 'y:/cfb-git/templates', cfb.Templates.tp_cs2010, cfb.False, cfb.False, null, null);
cls.namespace = 'javans';
cfb.build(mod, 'y:/cfb-git/java', 'y:/cfb-git/templates', cfb.Templates.tp_java, cfb.False, cfb.False, null, null);
cls.namespace = 'qtns';
cfb.build(mod, 'y:/cfb-git/qt', 'y:/cfb-git/templates', cfb.Templates.tp_qtWindows, cfb.False, cfb.False, null, null);
