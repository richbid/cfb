//#include ../cfb.js
var mod = new CfModule('function0', 'ns');
var cls = mod.addCls('cls');
cls.addProp('PBool', cfb.Types.vt_bool);
var func = cls.addFunc('FuncBool', cfb.Types.vt_bool);
func = cls.addFunc('FuncBytes', cfb.Types.vt_bytes);
func = cls.addFunc('FuncDate', cfb.Types.vt_date);
func = cls.addFunc('FuncDateTime', cfb.Types.vt_datetime);
func = cls.addFunc('FuncDouble', cfb.Types.vt_double);
func = cls.addFunc('FuncFloat', cfb.Types.vt_float);
func = cls.addFunc('FuncInt32', cfb.Types.vt_int32);
func = cls.addFunc('FuncText', cfb.Types.vt_text);
func = cls.addFunc('FuncTime', cfb.Types.vt_time);
func = cls.addFunc('FuncUInt32', cfb.Types.vt_uint32);

cls.namespace = 'csns';
cfb.build(mod, 'y:/cfb-git/cs', 'y:/cfb-git/templates', cfb.Templates.tp_cs2010, cfb.False, cfb.False, null, null);
cls.namespace = 'javans';
cfb.build(mod, 'y:/cfb-git/java', 'y:/cfb-git/templates', cfb.Templates.tp_java, cfb.False, cfb.False, null, null);
cls.namespace = 'qtns';
cfb.build(mod, 'y:/cfb-git/qt', 'y:/cfb-git/templates', cfb.Templates.tp_qtWindows, cfb.False, cfb.False, null, null);
