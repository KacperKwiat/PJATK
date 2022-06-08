


<?php
$dbuser = 'root';
$dbpass = '';
$db = new PDO("mysql:host=localhost;dbname=projekt", $dbuser,$dbpass) or die ("Unsuccessful connection");

if(isset($_POST['submit'])){
    $yourAcc=$_POST['your_account'];
    $reciverAcc=$_POST['reciver_account'];
    $transfermoney=$_POST['moneyTransfer'];
    $result1=$db->query("select * from account where number='$yourAcc'");
    $result2=$db->query("select * from account where number='$reciverAcc'");
    if($result1->rowCount()!=1 && $result2->rowCount()!=1){
        echo "Given account number doesnt exist ".'<br>'."Try again";
        header("refresh:4;url=transferForm.php");
        exit(1);
    }
    $sql="select money_amount from account where number='$yourAcc'";
    $money=$db->query($sql);
    $takenmoney=$money->fetch(PDO::FETCH_OBJ);
    $moneyAcc=0;
    foreach ($takenmoney as $value){
        $moneyAcc=$value;
    }
    if($moneyAcc<$transfermoney){
        echo "Sorry you dont have enough money to make this transfer ".'<br>';
        header("refresh:5;url=accountLog.php");

    }
    $moneyAcc=$moneyAcc-$transfermoney;
    $sql_1="UPDATE `account` SET `money_amount` = '$moneyAcc' WHERE `account`.`number` ='$yourAcc'";
    $db->query($sql_1);
    $sql_2="select money_amount from account where number='$reciverAcc'";
    $money2=$db->query($sql_2);
    $gotMoney=$money2->fetch(PDO::FETCH_OBJ);
    $recMoney=0;
    foreach ($gotMoney as $value){
        $recMoney=$value;
    }
    $recMoney=$recMoney+$transfermoney;
    $sql_3="UPDATE `account` SET `money_amount` = '$recMoney' WHERE `account`.`number` ='$reciverAcc'";
    $db->query($sql_3);
}?>
<body>
<center>


<p>Thank you for using our services</p>
<p>Your transfer has been delivered</p>
<p>Wait we will redirect you back to your account.</p>

</center>
</body>
<?php

header("refresh:7;url=transferForm.php");
