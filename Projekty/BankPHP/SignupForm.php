<?php

session_start();
?>
<!DOCTYPE html>
<html lang="en">
<head>
    <title>Golden Horizon Bank</title>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0"> <meta http-equiv="X-UA-Compatible" content="ie=edge">
    <link href="https://fonts.googleapis.com/css?family=Amatic+SC|Raleway:100,200,600,700" rel="stylesheet">
    <link rel="stylesheet" href="style2.css">
</head>
<body>
<?php
if(empty($_SESSION['user'])) {
    ?>
    <html>

    <form action="accountSign.php" method="post">
        <input type="text" name="login" placeholder="Enter your login" required>
        <br>
        <input type="password" name="password" placeholder="Enter your password" required>
        <br>
        <input type="submit" name="submit" value="Sign Up"><br>
        <button><a href="LoginForm.php">Click to Log In</a></button>
    </form>
    </html>
    <?php
}

?>
</body>
</html>
