//#include ../cfb.js
function addArgTest(fx) {
    fx.addArg('ArgBool', cfb.Types.vt_bool);
    fx.addArg('ArgBytes', cfb.Types.vt_bytes);
    fx.addArg('ArgDate', cfb.Types.vt_date);
    fx.addArg('ArgDateTime', cfb.Types.vt_datetime);
    fx.addArg('ArgDouble', cfb.Types.vt_double);
    fx.addArg('ArgFloat', cfb.Types.vt_float);
    fx.addArg('ArgInt32', cfb.Types.vt_int32);
    fx.addArg('ArgText', cfb.Types.vt_text);
    fx.addArg('ArgTime', cfb.Types.vt_time);
    fx.addArg('ArgUInt32', cfb.Types.vt_uint32);    
}
var mod = new CfModule('argument0', 'ns');
var cls = mod.addCls('cls');
cls.addProp('PBool', cfb.Types.vt_bool);
var func = cls.addFunc('FuncBool', cfb.Types.vt_bool);
addArgTest(func);
func = cls.addFunc('FuncBytes', cfb.Types.vt_bytes);
addArgTest(func);
func = cls.addFunc('FuncDate', cfb.Types.vt_date);
addArgTest(func);
func = cls.addFunc('FuncDateTime', cfb.Types.vt_datetime);
addArgTest(func);
func = cls.addFunc('FuncDouble', cfb.Types.vt_double);
addArgTest(func);
func = cls.addFunc('FuncFloat', cfb.Types.vt_float);
addArgTest(func);
func = cls.addFunc('FuncInt32', cfb.Types.vt_int32);
addArgTest(func);
func = cls.addFunc('FuncText', cfb.Types.vt_text);
addArgTest(func);
func = cls.addFunc('FuncTime', cfb.Types.vt_time);
addArgTest(func);
func = cls.addFunc('FuncUInt32', cfb.Types.vt_uint32);
addArgTest(func);

cls.namespace = 'csns';
cfb.build(mod, 'y:/cfb-git/cs', 'y:/cfb-git/templates', cfb.Templates.tp_cs2010, cfb.False, cfb.False, null, null);
cls.namespace = 'javans';
cfb.build(mod, 'y:/cfb-git/java', 'y:/cfb-git/templates', cfb.Templates.tp_java, cfb.False, cfb.False, null, null);
cls.namespace = 'qtns';
cfb.build(mod, 'y:/cfb-git/qt', 'y:/cfb-git/templates', cfb.Templates.tp_qtWindows, cfb.False, cfb.False, null, null);
