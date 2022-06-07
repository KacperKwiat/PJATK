<?php
if(isset($_POST['submit'])){
    $log=$_POST['login'];
    $dbuser = 'root';
    $dbpass = '';
    $db = new PDO("mysql:host=localhost;dbname=projekt", $dbuser,$dbpass) or die ("Unsuccessfulconnection");
    $sql="select *from logins where login ='$log'";
    $result=$db->query($sql);
    if($result->rowCount()==1){
        $newLine="\n";
        $log=$newLine.$log;
        $log .=": \n";
        $data=$_POST['clientSurvey'];
        $seperator="\n----------------------------------------------";
        $fp=fopen('data.txt','a');
        fwrite($fp,$log);
        fwrite($fp,$data);
        fwrite($fp,$seperator);
        fclose($fp);
        echo "Data has been saved ";
        header("refresh:3;url=opinion_form.php");

    }else{
        echo "Given login doesnt exist in our databse try again ";
        header("refresh:3;url=opinion_form.php");
    }

}else{
    echo "Sorry we didnt receive your survey try again";
    header("refresh:3;url=opinion_form.php");
}
