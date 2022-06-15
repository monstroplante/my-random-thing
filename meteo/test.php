<?php // Ouverture du fichier contenant les donn�es
$url = 'https://api.weatherapi.com/v1/current.json?key=blblblblbl=paris&aqi=yes';
$obj = json_decode(file_get_contents($url), true);
echo $obj['current']['temp_c'];
echo "<br>";
echo $obj['current']['is_day'];
echo "<br>";
echo $obj['current']['wind_kph'];
echo "<br>";
echo $obj['current']['humidity'];