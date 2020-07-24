{$M 49152,0,320000}
{$F- $a+ $b- $g+ $i- $r- $s+ $x+}

Program Example3;
uses Crt,Dos;

var
  i : integer;
  ticks1Ms : longint;


function getTicksIn60Ms : longint;
var
  Hour,Min,Sec,HSec : word;
  prev : word;
  counter : longint;
  i : integer;

begin
	i := 0;
	counter := 0;

	repeat
	  GetTime(Hour,Min,Sec,HSec);

	  if i = 0 then
	  begin
		if HSec = prev then i := 1;
	  end
	  else
	  begin
		if HSec = prev then counter := counter + 1 else i := 2;
	  end;

	  prev := HSec;
	until i = 2;

writeln(counter);
readln;

    getTicksIn60Ms := counter;
end;




procedure wait_ms(ms : word);
var
   c2, i : longint;
   ticks : longint;
   dummy : longint;
   prev_dummy : longint;
   temp, temp2 : real;

   Hour,Min,Sec,HSec : word;
begin
    dummy := 0;
    c2 := 0;
    prev_dummy := 0;
    ticks := ms * ticks1Ms;
    temp := 24571511;
    temp2 := 46;

    for i := 0 to ticks do
    begin
      GetTime(Hour,Min,Sec,HSec);
      if dummy = prev_dummy then c2 := c2 + 1 else dummy := 2;
      prev_dummy := dummy;
    end;
end;






begin
ticks1Ms := getTicksIn60Ms div 60;

for i := 0 to 5 do
begin
     wait_ms(1000);
     write('second ');
     writeln(i);
end;

end.