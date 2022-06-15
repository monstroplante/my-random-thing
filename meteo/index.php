<!DOCTYPE html>
<html lang="fr">

<head>
    <!-- Design by foolishdeveloper.com -->
    <title>Fait par moi pour de vrai</title>

    <link rel="stylesheet" href="style.css">
    <link href="https://fonts.googleapis.com/css2?family=Poppins:wght@300;500;600&display=swap" rel="stylesheet">
    <!--Stylesheet-->
    <style media="screen">
    form * {
        font-family: 'Poppins', sans-serif;

        <?php // Ouverture du fichier contenant les donn�es
        $url='https://api.weatherapi.com/v1/current.json?key=3ca5e839b9c94e659bd102536221105&q=paris&aqi=yes';
        $obj=json_decode(file_get_contents($url), true);
        $Temp=$obj['current']['temp_c'];

        $Lum=$obj['current']['is_day'];

        $spd=$obj['current']['wind_kph'];
        $Hum=$obj['current']['humidity'];

        if ($Lum==1) {
            echo 'color: #000000;';
        }else {
            echo 'color: #ffffff;';
        }

        ?>
        letter-spacing: 0.5px;
        outline: none;
        border: none;
        transition: transform .1s;
        margin: 0 auto;
    }

    .day_night{
        <?php
        if ($Lum==1) {
            echo 'background-color: #ffffff;';
        }else {
            echo 'background-color: #000000;';
        }
        ?>
    }

    .center {
        display: block;
        margin-left: auto;
        margin-right: auto;
    }

    .center:hover {
        transform: scale(1.5);
    }

    .center-color-invert {
        display: block;
        margin-left: auto;
        margin-right: auto;
        <?php // Ouverture du fichier contenant les donn�es
        if ($Lum==1) {
            echo 'filter: invert(1);';
        }

        ?>
    }

    .center-color-invert:hover {
        transform: scale(1.5);
    }

    .rotate-center {
        -webkit-animation: rotate-center 5s linear infinite both;
        animation: rotate-center 5s linear infinite both;
    }


    @-webkit-keyframes rotate-center {
        0% {
            -webkit-transform: rotate(0);
            transform: rotate(0);
        }

        100% {
            -webkit-transform: rotate(360deg);
            transform: rotate(360deg);
        }
    }

    @keyframes rotate-center {
        0% {
            -webkit-transform: rotate(0);
            transform: rotate(0);
        }

        100% {
            -webkit-transform: rotate(360deg);
            transform: rotate(360deg);
        }
    }
    </style>
</head>

<body class=day_night>

<div class="background">
    <div class="shape"></div>
    <div class="shape"></div>
</div>
<div class="zoom">
    <form>

        <div align="center">
            <p>
                <font size="+2">Grandeurs physiques</font>
            </p>
            <table border='0'>
                <tr>
                    <td> Température : </td>
                    <td>
                        <?php
echo "$Temp";
?>
                    </td>
                    <td> °C </td>

                    <td>
                        <?php
if ($Temp >= 20) {
    echo '<img src="animated\clear-day.svg" width="100" height="100" class="center" > ';
}

if ($Temp <= 0) {
    echo '<img src="animated\snowflake.svg" width="100" height="100" class="center" > ';
}

if ($Temp > 0 && $Temp < 20) {
    echo '<img src="animated\overcast-day.svg" width="100" height="100" class="center" > ';
}

?>
                    </td>

                </tr>
                <br>
                <tr>
                    <td> Humidité : </td>
                    <td> <?php
echo "$Hum";
?>
                    </td>
                    <td> % </td>
                    <td>
                        <?php
if ($Hum >= 70) {
    echo '<img src="animated\rain.svg" width="100" height="100" class="center" > ';
} else if ($Hum < 70) {
    echo '<img src="animated\clear-day.svg" width="100" height="100" class="center" > ';
}

?>

                    </td>
                </tr>
                <br>
                <tr>
                    <td> Vitesse vent</td>
                    <td> <?php
echo "$spd";
?>
                    </td>
                    <td> km/h </td>
                    <td>
                        <?php
if ($spd > 50) {
    echo '<img src="animated\wind.svg" width="100" height="100" class="center-color-invert"> ';
} else {
    echo '<img src="animated\mist.svg" width="100" height="100" class="center-color-invert">';
}

?>
                    </td>
                </tr>

            </table>
        </div>

    </form>
</div>
</body>

</html>