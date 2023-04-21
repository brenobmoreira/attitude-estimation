Attitude Estimation Exam - Breno B Moreira

Como pedido foi usando a "aerospace rotation sequence", sendo utilizada as equações:

tan(fi) = Gpy/Gpz -> variando entre -180º e +180º // roll angle
tan(theta) = Gpx/sqrt(Gpy^2+Gpz^2) -> variando entre -90º e +90º // pitch angle

Por ser mais familiarizado com Python, primeiro fiz o desafio nessa linguagem, para ter noção do que eu precisaria fazer, e depois repassei para C++
O arquivo de .py basta dar run que irá realizar "Pitch and Roll estimator" e irá criar um arquivo em CSV para poder visualizar.

TANTO EM PYTHON QUANTO EM C++:

1. funções para calcular os ângulos
2. formatação da data (data parsing)
3. cálculo de todos ângulos para cada horário
4. conversão dos ângulos de rad para graus
5. criação de um arquivo contendo o item 3
6. para o cálculo do Roll Angle por ele poder estar entre -180º e 180º, foi utilizado a função ATAN2, que retorna automaticamente o ângulo no quadrante correto baseado
nos sinais de cada argumento.

PARA PYTHON:
- o .log precisa estar na pasta do .py
- caso for utilizar outro arquivo as informações precisam estar na ordem do attitude_.log:
    => <time_stamp_ms; accel_x_axis; accel_y_axis; accel_z_axis>

- as axis estão em millig unit
- no arquivo CSV o timestamp ficará convertido para o tempo humano

PARA C++:
