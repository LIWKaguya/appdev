<?php
$peaks = $_POST['peaks'];
$max = $_POST['max'];
$id = $_POST['ID'];
$today = date("Y-m-d H;i;s");
$record = $today . ", " . $id . ", " . $peaks . ", " . $max . "\n";
// this will post to public_html/php/sound.log
$file = "sound.log";
if(file_exists($file))
    $fp = fopen($file, "a"); // append
else
    $fp = fopen($file, "w"); // write 
fwrite($fp, $record);
fclose($fp);
echo "From e1900315 Le Hung\n";
?>

