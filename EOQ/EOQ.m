clc; clear all;
%--------------------------------------------------------------------------
%1) Determinar parametros de la funcion de costo
fprintf('---------------------------------------------------------\n')
fprintf('-------------------------PARTE 1-------------------------\n')
fprintf('---------------------------------------------------------\n')
d_ = 10e3;  %tasa de 10000 galones por mes
c_ = 3.5;     %precio de 3.50 pesos por galon
k_ = 2e3;    %costo de preparacion para ordenar un lote
h_ = 0.04;    %costo de mantener una unidad en inventario por unidad de tiempo
fprintf('La tasa es de: %d galones/mes \n', d_)
fprintf('El costo unitario por galon es de: $%.1f \n', c_)
fprintf('El costo de preparacion para ordenar un lote es de: $%d \n', k_)
fprintf('El costo de mantener inventario es de: $ %.2f por galon por mes\n', h_)
%--------------------------------------------------------------------------
%2) Encuentar el valor critico de Q que minimice la funcion. (CTinv)
fprintf('\n---------------------------------------------------------\n')
fprintf('-------------------------PARTE 2-------------------------\n')
fprintf('---------------------------------------------------------\n')
funcion = '((k*d)/Q)+(c*d)+((h*Q)/2)';   %Tecleamos la funcion como string
f =str2func(['@(k,d,Q,c,h)',funcion]);   %Convertimos string a funcion matematica

syms F(k,d,Q,c,h);                       %Decimos cuales son variables
fprintf('\nLa funcion CTinv es: ')
F(k,d,Q,c,h) = f                        %

Df = diff(F,Q);                    %Derivamos respecto a la variable Q

syms Derivada(k,d,Q,h);
fprintf('\nSu derivada respecto a Q es: ')
Derivada(k,d,Q,h) = Df

Min = solve(Df, Q);                      %Despejamos respecto a Q

syms Minimo(k,d,h);
fprintf('\nSi igualamos a 0 y despejamos Q: ')
Minimo(k,d,h) = Min                       %Evaluamos con el valor minimo

Critico = Minimo(k_, d_, h_);
%format bank
Q_ = Critico(1);                        %Debido a que se sacó raiz al despejar
                                        %solo nos quedamos con raiz positiva
fprintf('\nSustituyendo los parametros en la raiz positiva: ')
Q_ = double(Q_)                        %Convertimos el valor en decimal


%--------------------------------------------------------------------------
%3) 
%   ¿Cual es el tamaño de lote minimo?
fprintf('\n---------------------------------------------------------\n')
fprintf('-------------------------PARTE 3-------------------------\n')
fprintf('---------------------------------------------------------\n')
fprintf('Tamaño de lote minimo es de: %.2f galones \n\n', Q_ )



%   ¿Que costo conllevaría almacenar dicha cantidad durante un ciclo
%Basta con evaluar las variables en la funcion inicial (CTinv)
CT_inv = F(k_,d_,Q_,c_,h_);
CT_inv = double(CT_inv);                %Convertimos el valor en decimal
fprintf('El costo de almacenar durante un ciclo es: $%.2f \n\n', CT_inv)

%   ¿Cuanto tiempo para que se agote dicha cantidad?
Tiempo_agote = Q_/d_;
fprintf('El tiempo para que se agote dicha cantidad es: %.2f meses \n\n', Tiempo_agote)
    
    
    
    