<?php

$cookie_name = "vote";
?>
<!DOCTYPE html>
<html lang="en">
<head>
    <title>Golden Horizon Bank</title>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0"> <meta http-equiv="X-UA-Compatible" content="ie=edge">
    <link href="https://fonts.googleapis.com/css?family=Amatic+SC|Raleway:100,200,600,700" rel="stylesheet">
    <link rel="stylesheet" href="style.css">
</head>
<body>
<?php
if(!isset($_COOKIE[$cookie_name])) {
?>



    <html>
    <center>
    <form action="saveHelp.php" method="post">
        <input type="email" name="email" placeholder="Enter your email" style="width: 150px; height: 30px " required>
        <br>
        <textarea name="clientHelp" placeholder="How can we help you?" maxlength="250" style="width: 300px;height: 300px"></textarea>
        <br>
        <input type="submit" name="submit" value="Submit" style="width: 150px; height: 30px;font-size: large"><br>

    </form>
    <?php
    } else {
        echo "Cookie " . $cookie_name . " is set!".'<br>';
        echo "We have recived your data please be patient w will contact you soon. ".'<br>';
    }
    ?>
        <input type="button" value="Go back" onclick="history.back()">
    </center>
    </html>

</body>
</html>
