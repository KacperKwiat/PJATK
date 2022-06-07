
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

    <html>
    <center>

    <h1>Make your transfer</h1>
    <form action="transfer.php" method="post">
        <input type="text" name="your_account" placeholder="Enter your account number" style="width: 300px"required>
        <input type="text" name="reciver_account" placeholder="Enter account number to transfer" style="width: 300px"required>
        <br>
        <input type="number double" name="moneyTransfer" min="1" placeholder="Amount to transfer" style="width: 200px"required>
        <br>
        <input type="submit" name="submit" value="Submit"><br>
        <input type="button" value="Go back" onclick="history.back()">

    </form>
    </center>
    </html>

</body>
</html>
<?php
