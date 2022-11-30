    .global _PidCalculation
    
    .global _PidCalc2

_PidCalculation:
 				
    CTXTSWP #1
        ;xmemory = x_memory_buffer;
    MOV #(_x_memory_buffer), W9
        ;ymemory = y_memory_buffer;
    MOV #(_y_memory_buffer), W11
        ;result = __builtin_clr_prefetch(&xmemory, &xVal, 2, &ymemory, &yVal, 2, 0, B);
    CLR A, [W9]+=2, W5, [W11]+=2, W4
    MOVSAC A, [W9]+=2, W4, [W11]+=2, W5 
   ; MOV W10, [W15-8]
   ; MOV W8, [W15-6]
        ;result = __builtin_mac(result, xVal, yVal,&xmemory, &xVal, 2, &ymemory, &yVal, 2, 0, B);
   ; MOV W8, [W15-10]
   ; MOV W10, [W15-12]
    MAC W4*W5, A, [W9]+=2, W5, [W11]+=2, W4
    ;MOV W8, _xmemory
    ;MOV W10, _ymemory
    ;MOV W5, _xVal
    ;MOV W4, _yVal
        ;asm("CTXTSWP #0");
    CTXTSWP #0
 
    RETURN

_PidCalc2:
    CTXTSWP #1
    MOV #(_x_memory_buffer), W9
    MOV #(_y_memory_buffer), W11
    MOVSAC A, [W9]+=2, W4, [W11]+=2, W5 
    MAC W4*W5, A, [W9]+=2, W5, [W11]+=2, W4
    MAC W4*W5, A, [W9]+=2, W5, [W11]+=2, W4
    MAC W4*W5, A, [W9]+=2, W5, [W11]+=2, W4
    MAC W4*W5, A, [W9]+=2, W5, [W11]+=2, W4
    MAC W4*W5, A, [W9]+=2, W5, [W11]+=2, W4
    MAC W4*W5, A, [W9]+=2, W5, [W11]+=2, W4
    MAC W4*W5, A, [W9]+=2, W5, [W11]+=2, W4
    MAC W4*W5, A, [W9]+=2, W5, [W11]+=2, W4
    MAC W4*W5, A, [W9]+=2, W5, [W11]+=2, W4
    MAC W4*W5, A, [W9]+=2, W5, [W11]+=2, W4
    
    
    CTXTSWP #0
 
    RETURN
    .end
