//#include ../cfb.js
var mod = new CfModule('diagram0', 'ns');
var cls = mod.addCls('cls');
cls.addProp('PText', cfb.Types.vt_text);
cls.addFunc('trigger', cfb.Types.vt_int32);
var diagram = function () {
    var ns = mod.name + '.' + cls.name + '.';
    cfb.setNextFunction(ns + 'trigger', 'f0,f1,f2');
    cfb.setNextIfFunction(ns + 'f1', 'ifx0', 'tfx', 'ffx');        
    cfb.setNextIfFunction(ns + 'f2', 'ifx1', 'tf0,tf1,tf2', 'f0,f1,f2');
    cfb.setNextSwitchFunction(ns + 'tfx', 'sfx0', 'cfx,return -1,return -2');
    cfb.setNextSwitchFunction(ns + 'ffx', 'sfx1', 'cf0,cf1,cf2');            
    cfb.setNextWhileFunction(ns + 'cf0', 'wfx0', 'lfx');
    cfb.setNextWhileFunction(ns + 'cf1', 'wfx1', 'lf0,lf1,lf2');        
    cfb.setNextIfFunction(ns + 'lf2', 'if9', 'tf10', '');
    cfb.setNextIfFunction(ns + 'lf2', 'if10', 'return -1', 'return -2');
    cfb.setNextWhileFunction(ns + 'tf10', 'lf10', '');
};   
cfb.build(mod, 'y:/cfb-git/cs', 'y:/cfb-git/templates', cfb.Templates.tp_cs2010, cfb.False, cfb.False, diagram, null);
cfb.build(mod, 'y:/cfb-git/java', 'y:/cfb-git/templates', cfb.Templates.tp_java, cfb.False, cfb.False, diagram, null);
cfb.build(mod, 'y:/cfb-git/qt', 'y:/cfb-git/templates', cfb.Templates.tp_qtWindows, cfb.False, cfb.False, diagram, null);
