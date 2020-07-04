<?php 
	// MAIN MENU
	$filename = 'main_screenshot_SALIDA.VGA_DPAC2.COL.bmp';
	$fileout = 'SALIDA.VGA';
	$filepal = 'DPAC2.COL';

	// GAME OVER
	$filename = 'game_over_GAMEO.VGA.bmp';
	$fileout = 'GAMEO.VGA';
	$filepal = 'GAMEO.COL';


	$filesize = filesize($filename);

	$handle = fopen($filename, 'r');
	$contents = fread($handle, $filesize);
	fclose($handle);

	$pallete = substr($contents, 54, 1024);
	$data =  substr($contents, 1078);

	$pallete3 = "";

	for($i = 0; $i < 1024; $i+=4) {
		$r = round(ord($pallete[$i + 2]) / 4.2);
		$g = round(ord($pallete[$i + 1]) / 4.2);
		$b = round(ord($pallete[$i + 0]) / 4.2);
		$pallete3 .= chr($r) . chr($g) . chr($b);
	}


	$handle = fopen($filepal, 'w');
	$contents = fwrite($handle, $pallete3);
	fclose($handle);
	
	$lenghtData = strlen($data);
	$flippedData = "";

	for($i = 1; $i <= 200; $i++) {
		$flippedData .= substr($data, $lenghtData - ($i * 320),320);
	}
	
	$handle = fopen($fileout, 'w');
	$contents = fwrite($handle, $flippedData);
	fclose($handle);

	echo 'success!';


