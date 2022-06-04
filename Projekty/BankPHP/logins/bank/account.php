
<!DOCTYPE html>
<html lang="en">
<head>
    <title>Golden Horizon Bank</title>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0"> <meta http-equiv="X-UA-Compatible" content="ie=edge">
    <link href="https://fonts.googleapis.com/css?family=Amatic+SC|Raleway:100,200,600,700" rel="stylesheet">
    <link rel="stylesheet" href="style.css">
</head>
<center>
    <body>
    <?php
    include 'C:\Git\PJATK\Projekty\BankPHP\logins\loginin.php';
    include 'C:\Git\PJATK\Projekty\BankPHP\logins\signingin.php';
    echo "Witamy w banku";
    $connect= mysqli_connect("127.0.0.1","root","","projekt");
    $sql="select id from logins where login ='$login'";
    echo $sql;
    ?>
    </body>
</center>

</html>

