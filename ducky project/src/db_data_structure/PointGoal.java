package db_data_structure;

//������һ��ѧԺ������ƻ�����һ����ݵļ�¼�Ͷ�ȡ
public class PointGoal {
	String school_name;// ѧԺ�� ���ﳬ�ӣ�
	int u_school_id; // ѧԺ�Ķ�Ӧ��ʶ��
	float a1; // A1�γ�Ӧ�ôﵽ�ı�׼ѧ��
	float a2; // A2�γ�Ӧ�ôﵽ�ı�׼ѧ��
	float a3; // A3�γ�Ӧ�ôﵽ�ı�׼ѧ��
	float b1; // B1�γ�Ӧ�ôﵽ�ı�׼ѧ��
	float b2; // B2�γ�Ӧ�ôﵽ�ı�׼ѧ��
	float b3; // B3�γ�Ӧ�ôﵽ�ı�׼ѧ��
	float c1; // C1�γ�Ӧ�ôﵽ�ı�׼ѧ��
	float c2; // C2�γ�Ӧ�ôﵽ�ı�׼ѧ��
	float c3; // C3�γ�Ӧ�ôﵽ�ı�׼ѧ��
	float d1; // D1�γ�Ӧ�ôﵽ�ı�׼ѧ��
	float d2; // D2�γ�Ӧ�ôﵽ�ı�׼ѧ��
	float d3; // D3�γ�Ӧ�ôﵽ�ı�׼ѧ��
	float e1; // E1�γ�Ӧ�ôﵽ�ı�׼ѧ��
	float e2; // E2�γ�Ӧ�ôﵽ�ı�׼ѧ��
	float e3; // E3�γ�Ӧ�ôﵽ�ı�׼ѧ��
	float f1; // F1�γ�Ӧ�ôﵽ�ı�׼ѧ��
	float f2; // F2�γ�Ӧ�ôﵽ�ı�׼ѧ��
	float f3; // F3�γ�Ӧ�ôﵽ�ı�׼ѧ��

	public String getSchool_name() {
		return school_name;
	}

	public void setSchool_name(String schoolName) {
		school_name = schoolName;
	}

	public int getU_school_id() {
		return u_school_id;
	}

	public void setU_school_id(int uSchoolId) {
		u_school_id = uSchoolId;
	}

	public float getA1() {
		return a1;
	}

	public void setA1(float a1) {
		this.a1 = a1;
	}

	public float getA2() {
		return a2;
	}

	public void setA2(float a2) {
		this.a2 = a2;
	}

	public float getA3() {
		return a3;
	}

	public void setA3(float a3) {
		this.a3 = a3;
	}

	public float getB1() {
		return b1;
	}

	public void setB1(float b1) {
		this.b1 = b1;
	}

	public float getB2() {
		return b2;
	}

	public void setB2(float b2) {
		this.b2 = b2;
	}

	public float getB3() {
		return b3;
	}

	public void setB3(float b3) {
		this.b3 = b3;
	}

	public float getC1() {
		return c1;
	}

	public void setC1(float c1) {
		this.c1 = c1;
	}

	public float getC2() {
		return c2;
	}

	public void setC2(float c2) {
		this.c2 = c2;
	}

	public float getC3() {
		return c3;
	}

	public void setC3(float c3) {
		this.c3 = c3;
	}

	public float getD1() {
		return d1;
	}

	public void setD1(float d1) {
		this.d1 = d1;
	}

	public float getD2() {
		return d2;
	}

	public void setD2(float d2) {
		this.d2 = d2;
	}

	public float getD3() {
		return d3;
	}

	public void setD3(float d3) {
		this.d3 = d3;
	}

	public float getE1() {
		return e1;
	}

	public void setE1(float e1) {
		this.e1 = e1;
	}

	public float getE2() {
		return e2;
	}

	public void setE2(float e2) {
		this.e2 = e2;
	}

	public float getE3() {
		return e3;
	}

	public void setE3(float e3) {
		this.e3 = e3;
	}

	public float getF1() {
		return f1;
	}

	public void setF1(float f1) {
		this.f1 = f1;
	}

	public float getF2() {
		return f2;
	}

	public void setF2(float f2) {
		this.f2 = f2;
	}

	public float getF3() {
		return f3;
	}

	public void setF3(float f3) {
		this.f3 = f3;
	}

	public void setData(int _type, float _data) {
		switch (_type) {
		case (enCourseType.CT_A1 - 1):
			this.setA1(_data);
			break;
			
		case (enCourseType.CT_A2 - 1):
			this.setA2(_data);
			break;
			
		case (enCourseType.CT_A3 - 1):
			this.setA3(_data);
			break;

		case (enCourseType.CT_B1 - 1):
			this.setB1(_data);
			break;

		case (enCourseType.CT_B2 - 1):
			this.setB2(_data);
			break;

		case (enCourseType.CT_B3 - 1):
			this.setB3(_data);
			break;

		case (enCourseType.CT_C1 - 1):
			this.setC1(_data);
			break;

		case (enCourseType.CT_C2 - 1):
			this.setC2(_data);
			break;

		case (enCourseType.CT_C3 - 1):
			this.setC3(_data);
			break;

		case (enCourseType.CT_D1 - 1):
			this.setD1(_data);
			break;

		case (enCourseType.CT_D2 - 1):
			this.setD2(_data);
			break;

		case (enCourseType.CT_D3 - 1):
			this.setD3(_data);
			break;

		case (enCourseType.CT_E1 - 1):
			this.setE1(_data);
			break;

		case (enCourseType.CT_E2 - 1):
			this.setE2(_data);
			break;

		case (enCourseType.CT_E3 - 1):
			this.setE3(_data);
			break;

		case (enCourseType.CT_F1 - 1):
			this.setF1(_data);
			break;

		case (enCourseType.CT_F2 - 1):
			this.setF2(_data);
			break;

		case (enCourseType.CT_F3 - 1):
			this.setF3(_data);
			break;
		default:
			break;
		}
	}
}
