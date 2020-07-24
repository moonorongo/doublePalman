uses
    crt;

type

    rec1 = record
          Nombre : string[10];
          puntaje : longint;
          end;

    hof =  array [1..5] of rec1;

var
   arch : file of hof;
   reg : hof;



procedure Sort_records (var p : hof);
var
   x,y : byte;
   pun_aux : rec1;

begin;
for x := 5 downto 1 do
    for y := 5 downto x do
        begin
             if p[x].puntaje < p[y].puntaje then
                begin;
                      pun_aux.nombre := p[y].nombre;
                      pun_aux.puntaje := p[y].puntaje;

                      p[y].puntaje := p[x].puntaje;
                      p[x] := pun_aux;
                end;
        end;
end;








begin;
assign (arch,'pacman.rec');
rewrite (arch);
reg[1].nombre := 'Thanks to';
reg[2].nombre := 'ZEEH!';
reg[3].nombre := 'KUATO!';
reg[4].nombre := 'Dobe';
reg[5].nombre := 'Willy';

reg[1].puntaje := 300000;
reg[2].puntaje := 200000;
reg[3].puntaje := 100000;
reg[4].puntaje := 50000;
reg[5].puntaje := 25000;

sort_records (reg);

clrscr;
writeln (reg[1].puntaje);
writeln (reg[2].puntaje);
writeln (reg[3].puntaje);
writeln (reg[4].puntaje);
writeln (reg[5].puntaje);

write (arch,reg);
close (arch);
end.
