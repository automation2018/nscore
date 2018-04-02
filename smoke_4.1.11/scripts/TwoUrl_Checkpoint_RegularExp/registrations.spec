nsl_decl_var(count);
//nsl_web_find(TextPfx="hi Thi?s is",TextSfx= %Rb, PAGE=checkpoint_smoke, FAIL = %Ord, ActionOnFail=Continue, SaveCount=count);
//nsl_web_find(TextPfx/RE/IC="hi Thi?s is",TextSfx/RE/IC = %Rb, PAGE=checkpoint_smoke, FAIL = %Ord, ActionOnFail=Continue, SaveCount=count);
nsl_web_find(TextPfx/RE/IC="hi Thi?s is",TextSfx/RE/IC = %Rb, PAGE=checkpoint_smoke, FAIL = %Ord, ActionOnFail=Stop, SaveCount=count);
