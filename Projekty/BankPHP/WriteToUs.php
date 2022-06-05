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

    <form action="costumerHelp.php" method="post">
        <input type="email" name="email" placeholder="Enter your email" required>
        <br>
        <textarea name="clientHelp" placeholder="How can we help you?"></textarea>
        <br>
        <input type="submit" name="submit" value="Submit"><br>

    </form>
    <?php
    } else {
        echo "Cookie " . $cookie_name . " is set!";
        echo "We have recived your data please be patient w will contact you soon. ";
    }
    ?>
    <a href="index.html">Go back</a>
    </html>
</body>
</html>
