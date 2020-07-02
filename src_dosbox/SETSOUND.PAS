uses
    crt;

type
    tipo_registro = record
                    dispositivo : byte;
                    mixing      : word;
                    sonido : boolean;
                    end;

var
   registro : tipo_registro;
   archivo : file of tipo_registro;
   vel : longint;
   c : char;
   salida : boolean;

function getvel : longint;
var
   contador : longint;
   hasta : byte;
begin;
clrscr;
contador := 0;

if mem[0:$46c] > 240 then repeat until mem[0:$46c] = 1;
hasta := mem[0:$46c];

repeat
inc (contador);
until mem[0:$46c] >= hasta + 10;

getvel := contador div 85000;
end;








begin;
clrscr;
Writeln (' Configuracion de sonido de Double Pacman. . .');

registro.sonido := true;
vel := getvel;
registro.mixing := (vel * 800) + 6000;

if registro.mixing > 10000 then registro.mixing := 10000;

write ('Frecuencia de Mezcla: ');
writeln (registro.mixing);
writeln;

writeln (' Dispositivo de sonido:  (ENTER Finaliza) ');
writeln;
writeln (' "A" - D/A on LPT1                   ');
writeln (' "B" - D/A on LPT2                   ');
writeln (' "C" - D/A on LPT3                   ');
writeln (' "D" - D/A on LPT1 & LPT2 (Stereo)   ');
writeln (' "E" - D/A on LPT1 & LPT2 (Mono)     ');
writeln (' "F" - Sound Blaster                 ');
writeln (' "G" - Stereo on one                 ');
writeln (' "H" - Quad on one                   ');
writeln (' ESC - NONE                          ');
salida := false;


repeat
      c := upcase(readkey);
      case c of
           'A' :  REGISTRO.DISPOSITIVO := 1;
           'B' :  REGISTRO.DISPOSITIVO := 2;
           'C' :  REGISTRO.DISPOSITIVO := 3;
           'D' :  REGISTRO.DISPOSITIVO := 4;
           'E' :  REGISTRO.DISPOSITIVO := 5;
           'F' :  REGISTRO.DISPOSITIVO := 7;
           'G' :  REGISTRO.DISPOSITIVO := 10;
           'H' :  REGISTRO.DISPOSITIVO := 14;
           #27 :  REGISTRO.DISPOSITIVO := 1;
      END;

if ((c = 'A') or
    (c = 'B') or
    (c = 'C') or
    (c = 'D') or
    (c = 'E') or
    (c = 'F') or
    (c = 'G') or
    (c = 'H') or
    (c = #27)) then salida := true else salida := false;

UNTIL salida;

gotoxy (1,16);
write ('Dispositivo: ');
writeln (c);



assign (archivo,'pacman.snd');
rewrite (archivo);
write (archivo,registro);
close (archivo);

writeln;
writeln ('Ok.');
writeln ('Para comenzar a jugar tipee "PAKMAN" y presione <ENTER>');
writeln;

end.









