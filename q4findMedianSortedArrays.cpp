#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2)
    {
        int tl = nums1.size() + nums2.size();
        int k = 0; //��¼��λ��
        int k2 = 0; //��¼k/2-1
        int i = 0; //nums1���±�
        int j = 0; //nums2���±�
        int i1 = 0; //��ʱ���±�
        int j1 = 0;
        double r = 0; //������

        //�������
        if (tl % 2 == 1) {

            // ���ܳ��žͿ�һ��
            if (nums1.size() == 0) {
                return nums2[tl / 2];
            }
            if (nums2.size() == 0) {
                return nums1[tl / 2];
            }

            k = tl / 2 + 1;
            while (k > 1) {
                k2 = k / 2 - 1;

                // ���k/2-1������±������
                if (i + k2 >= nums1.size()) {
                    i1 = nums1.size() - 1;
                } else {
                    i1 = i + k2;
                }
                if (j + k2 >= nums2.size()) {
                    j1 = nums2.size() - 1;
                } else {
                    j1 = j + k2;
                }

                if (nums1[i1] <= nums2[j1]) {
                    k = k - (i1 - i + 1);
                    i = i1 + 1;
                    if (i >= nums1.size()) {
                        r = nums2[j + k - 1];
                        return r;
                    }
                } else {
                    k = k - (j1 - j + 1);
                    j = j1 + 1;
                    if (j >= nums2.size()) {
                        r = nums1[i + k - 1];
                        return r;
                    }
                }
            }

            // ���ս׶Σ�����������Сֵ�����
            if (nums1[i] <= nums2[j])
                r = nums1[i];
            else
                r = nums2[j];
        }
        //���ż��
        if (tl % 2 == 0) {

            // ���ܳ��žͿ�һ��
            if (nums1.size() == 0) {
                return (nums2[tl / 2 - 1] + nums2[tl / 2]) / 2.0;
            }
            if (nums2.size() == 0) {
                return (nums1[tl / 2 - 1] + nums1[tl / 2]) / 2.0;
            }

            //��λ��������������ֻ��Ҫ��һ��
            k = tl / 2;
            while (k > 1) {
                k2 = k / 2 - 1;

                // ���k/2-1������±������
                if (i + k2 >= nums1.size()) {
                    i1 = nums1.size() - 1;
                } else {
                    i1 = i + k2;
                }
                if (j + k2 >= nums2.size()) {
                    j1 = nums2.size() - 1;
                } else {
                    j1 = j + k2;
                }

                if (nums1[i1] <= nums2[j1]) {
                    k = k - (i1 - i + 1);
                    i = i + k2 + 1;
                    if (i >= nums1.size()) {
                        r = (nums2[j + k - 1] + nums2[j + k]) / 2.0;
                        return r;
                    }
                } else {
                    k = k - (j1 - j + 1);
                    j = j + k2 + 1;
                    if (j >= nums2.size()) {
                        r = (nums1[i + k - 1] + nums1[i + k]) / 2.0;
                        return r;
                    }
                }
            }

            // ���ս׶Σ�����������Сֵ�����
            int r1 = 0; //��¼��һ����λ��
            int r2 = 0; //��¼�ڶ�����λ��
            if (nums1[i] <= nums2[j]) {
                r1 = nums1[i];
                i++;
                // �����±��п������
                if (i >= nums1.size()) {
                    r2 = nums2[j];
                    r = (r1 + r2) / 2.0;
                    return r;
                }
            } else {
                r1 = nums2[j];
                j++;
                // �����±��п������
                if (j >= nums2.size()) {
                    r2 = nums1[i];
                    r = (r1 + r2) / 2.0;
                    return r;
                }
            }
            if (nums1[i] <= nums2[j]) {
                r2 = nums1[i];
            } else {
                r2 = nums2[j];
            }
            r = (r1 + r2) / 2.0;
        }

        return r;
    }
};

int main()
{
    Solution s;
    // vector<int> nums1 = { 1, 3 };
    // vector<int> nums2 = { 2 };
    // vector<int> nums1 = { 1, 2, 7, 9 };
    // vector<int> nums2 = { 3, 5, 6, 8, 10 };

    // vector<int> nums1 = { 1, 2, 3, 4 };
    // vector<int> nums2 = { 5, 6, 7, 8, 9 };

    // vector<int> nums1 = { 1, 2, 7, 9 };
    // vector<int> nums2 = { 3, 5, 6, 8 };

    // vector<int> nums1 = { 1, 2 };
    // vector<int> nums2 = { 3, 4 };

    // vector<int> nums1 = {};
    // vector<int> nums2 = { 1, 2, 3, 4 };

    // vector<int> nums1 = { 1 };
    // vector<int> nums2 = { 2, 3, 4, 5, 6, 7 };
    vector<int> nums1 = { 1 };
    vector<int> nums2 = { 2, 3, 4, 5, 6, 7, 8 };

    cout << s.findMedianSortedArrays(nums1, nums2);
    cout << endl;

    system("pause");
    return 0;
}