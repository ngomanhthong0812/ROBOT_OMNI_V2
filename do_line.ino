//****bố trí cảm biến****//
//kết nối sensor: trai 0-1-2-3-4-5 phai
//trước moi:  42-43-44-45-46-47
void doc_cam_bien_do_line(int huong_cb)
{
  if(huong_cb == cb_truoc) //đọc 6 cảm biến trước và 6 cảm biến sau
  {
    //đọc 6 cảm biến trước
    sensor[0]=digitalRead(42);
    sensor[1]=digitalRead(43);
    sensor[2]=digitalRead(44);
    sensor[3]=digitalRead(45);
    sensor[4]=digitalRead(46);
    sensor[5]=digitalRead(47);
  }

  //lệch phải
  if     ((sensor[0]==0)&&(sensor[1]==0)&&(sensor[2]==0)&&(sensor[3]==0)&&(sensor[4]==0)&&(sensor[5]==1)) error= 5;
  else if((sensor[0]==0)&&(sensor[1]==0)&&(sensor[2]==0)&&(sensor[3]==0)&&(sensor[4]==1)&&(sensor[5]==1)) error= 4;
  else if((sensor[0]==0)&&(sensor[1]==0)&&(sensor[2]==0)&&(sensor[3]==0)&&(sensor[4]==1)&&(sensor[5]==0)) error= 3;
  else if((sensor[0]==0)&&(sensor[1]==0)&&(sensor[2]==0)&&(sensor[3]==1)&&(sensor[4]==1)&&(sensor[5]==0)) error= 2;
  else if((sensor[0]==0)&&(sensor[1]==0)&&(sensor[2]==0)&&(sensor[3]==1)&&(sensor[4]==0)&&(sensor[5]==0)) error= 1;
  //ở giữa
  else if((sensor[0]==0)&&(sensor[1]==0)&&(sensor[2]==1)&&(sensor[3]==1)&&(sensor[4]==0)&&(sensor[5]==0)) error=0;
  //lệch trái
  else if((sensor[0]==0)&&(sensor[1]==0)&&(sensor[2]==1)&&(sensor[3]==0)&&(sensor[4]==0)&&(sensor[5]==0)) error=-1;
  else if((sensor[0]==0)&&(sensor[1]==1)&&(sensor[2]==1)&&(sensor[3]==0)&&(sensor[4]==0)&&(sensor[5]==0)) error=-2;
  else if((sensor[0]==0)&&(sensor[1]==1)&&(sensor[2]==0)&&(sensor[3]==0)&&(sensor[4]==0)&&(sensor[5]==0)) error=-3;
  else if((sensor[0]==1)&&(sensor[1]==1)&&(sensor[2]==0)&&(sensor[3]==0)&&(sensor[4]==0)&&(sensor[5]==0)) error=-4;
  else if((sensor[0]==1)&&(sensor[1]==0)&&(sensor[2]==0)&&(sensor[3]==0)&&(sensor[4]==0)&&(sensor[5]==0)) error=-5;
  //trường hợp khác
  else  error = 0;
}
