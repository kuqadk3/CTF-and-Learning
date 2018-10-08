package youtube.source.a11x256.myapplication;

import android.os.Bundle;
import android.support.v7.app.AppCompatActivity;
import android.support.v7.widget.Toolbar;
import android.widget.Toast;

public class Main2Activity extends AppCompatActivity {
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView((int) C0240R.layout.activity_main2);
        setSupportActionBar((Toolbar) findViewById(C0240R.id.toolbar));
        Validate(getIntent().getExtras().get("key").toString());
    }

    String Validate(String f) {
        StringBuilder str = new StringBuilder(f);
        for (int i = 0; i < str.length(); i++) {
            for (int j = i; j < str.length() - 1; j++) {
                char t = str.charAt(j);
                str.setCharAt(j, str.charAt(j + 1));
                str.setCharAt(j + 1, t);
            }
        }
        if (str.toString().equals(String.valueOf(new char[]{'l', 'g', 'c', 'n', 'y', 'u', 'r', 'V', 'r', '3', '4', 'd', '0', 'D', 'f', '{', '_', '_', '3', '_', 'R', '}', '4', '3', 'n', 'a', '5', '0', '1'}))) {
            Toast.makeText(getApplicationContext(), String.valueOf(new char[]{'C', 'o', 'r', 'r', 'e', 'c', 't'}), 1).show();
        }
        return "" + str.toString();
    }
}
