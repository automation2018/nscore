nsl_decl_var(count);
nsl_web_find(TextPfx/RE/IC="hi Thi?s is",TextSfx/RE/IC = %Rb, PAGE=checkpoint_smoke, FAIL = %Ord, ActionOnFail=Stop, SaveCount=count);
